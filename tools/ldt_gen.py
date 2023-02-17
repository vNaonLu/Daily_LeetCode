#!/usr/bin/env python3
import sys
from argparse import RawTextHelpFormatter
# prevent generating __pycache__
sys.dont_write_bytecode = True

from utils import *
import cli


@cli.command(
    cli.arg("-v", "--verbose", dest="verbose", default=False, action="store_true",
            help="enable verbose logging."),
    cli.arg("-S", "--src", dest="src_path", default=str(PROJECT_ROOT), action="store",
            metavar="[Project_Root]", help="specify the source directory which contains CMakeLists.txt."),
    cli.arg("-B", "--build", dest="build_path", default=str(BUILD_ABSOLUTE), action="store",
            metavar="[Build_Path]", help="specify the directory to build. Default: './build'."),
    cli.arg("--debug", dest="debug_mode", default=False, action="store_true",
            help="generate the build file with debug flags."),
    cli.arg("--compile-commands", dest="compile_command", default=False, action="store_true",
            help="generate the compile_commands.json in the build directory."),
    cli.arg("--disable-leetcode-test", dest="disable_leetcode_test", default=False, action="store_true",
            help="disable generate the build files for the solutions tests."),
    cli.arg("--disable-infra-test", dest="disable_infra_test", default=False, action="store_true",
            help="disable generate the build files for the LeetCode structures tests."),
    formatter_class=RawTextHelpFormatter,
    name="gen", prog=GEN_SCRIPT_NAME,
    help=fixedWidth(
        "generate the CMake build files.",
        width=60
    ),
    description=fixedWidth(
        'A script to generate the CMake build files to build the project.'
    )
)
def ldtGen(args):
    LOG = prompt.Log.getInstance(verbose=getattr(args, "verbose"))
    SRC_PATH = Path(getattr(args, "src_path")).resolve()
    BUILD_PATH = Path(getattr(args, "build_path")).resolve()
    BUILD_FLAG = "Debug" if getattr(args, "debug_mode") else "Release"
    COMPILE_COMMAND_FLAG = "ON" if getattr(args, "compile_command") else "OFF"
    LEETCODE_TEST_FLAG = "OFF" if getattr(args, "disable_leetcode_test") else "ON"
    INFRA_TEST_FLAG = "OFF" if getattr(args, "disable_infra_test") else "ON"
    
    LOG.verbose("checking whether the CMakeLists.txt exists in the directory: {}", SRC_PATH)

    if not SRC_PATH.joinpath("CMakeLists.txt").exists():
        LOG.failure("there is no |CMakeLists.txt| exists in the directory: {}", SRC_PATH)
        return 1

    cmake = FindExecutable("cmake")

    if not cmake:
        LOG.failure("cmake not found.")
        return 1

    CMD = [
        cmake, "-S", SRC_PATH, "-B", BUILD_PATH,
        f"-DCMAKE_EXPORT_COMPILE_COMMANDS={COMPILE_COMMAND_FLAG}",
        f"-DCMAKE_BUILD_TYPE={BUILD_FLAG}",
        f"-DENABLE_LEETCODE_TEST={LEETCODE_TEST_FLAG}",
        f"-DENABLE_INFRA_TEST={INFRA_TEST_FLAG}",
    ]

    TASK = LOG.createTaskLog("Generate Build Files")

    def stdoutCallback(out: str):
        TASK.log(parseCMakeGenarateLog(out))
        LOG.verbose(out)

    with launchSubprocess(CMD) as proc:
        TASK.begin()
        asyncStdout(proc, stdoutCallback)

        if proc.poll() != 0:
            TASK.done("failed to generate the build files.", is_success=False)
            proc.stderr.seek(0)
            LOG.print(proc.stderr.read(), flag=LOG.VERBOSE)
            return 1

        TASK.done(is_success=True)

    return 0


if __name__ == "__main__":
    sys.exit(safeRun(ldtGen))
