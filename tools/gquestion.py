#!/usr/bin/python3
import sys
import os
import pathlib
import subprocess
from utils import local, template, modify
from leetcode import request as LeetCodeRequest
from leetcode.question import LeetCodeQuestion

prompt = "this file is generated by {}".format(os.path.basename(__file__))
proj_path = pathlib.Path(__file__).parent.parent.resolve()
sour_path = os.path.join(proj_path, "src")
list_csv = os.path.join(sour_path, "questions_list.csv")
log_csv = os.path.join(sour_path, "logs.csv")


class QuestionFile:
    def __init__(self, id: int):
        self.__id: str = str(id).zfill(4)
        self.__intv: str = local.id_folder(id)
        self.__name: str = "q{}.hpp".format(self.__id)
        self.__ut_name: str = "q{}_unittest.hpp".format(self.__id)
        self.__path: str = os.path.join(sour_path, self.__intv)

    def interval(self):
        return self.__intv

    def id(self):
        return int(self.__id)

    def src(self):
        return os.path.join(self.__path, self.__name)

    def unittest(self):
        return os.path.join(self.__path, self.__ut_name)

    def path(self):
        return self.__path


def add_question(qfile: QuestionFile, ques: LeetCodeQuestion):
    path = qfile.path()
    src = qfile.src()
    utsrc = qfile.unittest()
    desc = template.generate_question_description(prompt,
                                                  ques.id(),
                                                  ques.title(),
                                                  ques.description(50),
                                                  ques.constraints())

    utindex = os.path.join(path, "unittest.hpp")
    if not os.path.isdir(path):
        os.makedirs(path)
        print("[+] create directory: {}".format(path))
        template.generate_intv_unittest(utindex, qfile.interval())
        modify.unittest(os.path.join(
            sour_path, "unittest.cc"), qfile.id(), qfile.interval())

    if os.path.exists(src):
        print("[!] file exist: {}".format(src))
        return False
    else:
        template.generate_source(src, qfile.id(), desc, ques.code_snippet())
        subprocess.run(["code", src])

    if os.path.exists(utsrc):
        print("[!] file exist: {}".format(utsrc))
        return False
    else:
        template.generate_unittest(utsrc, qfile.id(), desc)
        subprocess.run(["code", utsrc])

    modify.log(log_csv, qfile.id())
    modify.question_list(list_csv, [qfile.id()])
    modify.subunittest(utindex, os.path.basename(utsrc))
    return True


if len(sys.argv) < 2:
    print("[Usage] <question number> ...")
else:
    if not os.path.exists(list_csv):
        template.generate_question_list(list_csv)
        solved = local.solved_question_ids()
        modify.question_list(list_csv, solved)

    modified_md = False

    for i in range(1, len(sys.argv)):
        qfile = QuestionFile(int(sys.argv[i]))
        slug = LeetCodeRequest.question_slug(qfile.id())
        if not slug:
            print("[-] question #{} does not exist.".format(qfile.id()))
            continue
        ques = LeetCodeQuestion(slug)

        if not ques.description():
            print("[-] question #{} needs a premium account.".format(qfile.id()))
            continue

        if add_question(qfile, ques):
            modified_md |= True
        else:
            print("[x] Failed to generate Question #{}".format(qfile.id()))

    if modified_md:
        modify.readme(
            os.path.join(proj_path, "README.md"),
            list_csv,
            log_csv)
