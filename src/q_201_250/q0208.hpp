
#ifndef LEETCODE_Q208_H__
#define LEETCODE_Q208_H__
#include <iostream>
#include <memory>
#include <unordered_map>

namespace l208 {
using namespace std;

/**
  * This file is generated by leetcode_add.py
  *
  * 208.
  *      Implement Trie (Prefix Tree)
  *
  * ––––––––––––––––––––––––––––– Description –––––––––––––––––––––––––––––
  *
  *   A <a href="https://en.wikipedia.org/wiki/Trie" target="_blank"> “trie”
  *   </a> (pronounced as "try") or “prefix tree” is a tree data structure
  *   used to efficiently store and retrieve keys in a dataset of strings.
  *   There are various applications of this data structure, such as
  *   autocomplete and spellchecker.
  *   
  *   Implement the Trie.
  *   
  *   - ‘Trie()’ Initializes the trie object.
  *   
  *   - ‘void insert(String word)’ Inserts the string ‘word’ into the trie.
  *   
  *   - ‘boolean search(String word)’ Returns ‘true’ if the string ‘word’
  *   is in the trie (i.e., was inserted before), and ‘false’ otherwise.
  *   
  *   - ‘boolean startsWith(String prefix)’ Returns ‘true’ if there is a
  *   previously inserted string ‘word’ that has the prefix ‘prefix’ , and
  *   ‘false’ otherwise.
  *
  * ––––––––––––––––––––––––––––– Constraints –––––––––––––––––––––––––––––
  *
  *   • ‘1 ≤ word.length, prefix.length ≤ 2000’
  *   • ‘word’ and ‘prefix’ consist only of lowercase English letters.
  *   • At most ‘3 × 10⁴’ calls “in total” will be made to ‘insert’ , ‘search’ , and ‘startsWith’ .
  *
*/

class Trie {
 private:
  class TrieNode {
   private:
    unordered_map<char, shared_ptr<TrieNode>> links;
    bool is_end;

   public:
    TrieNode() {
      is_end = false;
    }

    inline bool has(const char &c) const {
      return links.count(c);
    }

    inline shared_ptr<TrieNode> at(const char &c) const {
      return links.at(c);
    }

    inline void put(const char &c, unique_ptr<TrieNode> &&node) {
      links[c] = move(node);
    }

    inline void setEnd() {
      is_end = true;
    }

    inline bool end() const {
      return is_end;
    }
  };

  shared_ptr<TrieNode> m_root;

 public:
  Trie() {
    m_root = make_shared<TrieNode>();
  }

  void insert(string word) {
    auto node = m_root;
    for(const char &c : word){
      if(!node->has(c))
        node->put(c, make_unique<TrieNode>());
      node = node->at(c);
    }
    node->setEnd();
  }

  bool search(string word) {
    auto node = m_root;
    for(const char &c : word){
      if (!node->has(c)) return false;
      node = node->at(c);
    }
    return node->end();
  }

  bool startsWith(string prefix) {
    auto node = m_root;
    for (const char &c : prefix) {
      if (!node->has(c)) return false;
      node = node->at(c);
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
}  // namespace l208

#endif