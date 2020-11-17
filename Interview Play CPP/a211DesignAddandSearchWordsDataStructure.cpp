//
//  a211DesignAddandSearchWordsDataStructure.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class TrieNode {
    vector<TrieNode*> _children;
    bool _endOfWord;
public:
    TrieNode() {
        _children = vector<TrieNode*>(26, nullptr);
        _endOfWord = false;
    }
    
    void insert(const string& s, int start) {
        if (start == s.size()) {
            _endOfWord = true;
            return;
        }
        
        if (_children[s[start]-'a'] == nullptr) {
            _children[s[start]-'a'] = new TrieNode();
        }
        
        _children[s[start]-'a']->insert(s, start+1);
    }
    
    bool search(const string& s, int start) {
        if (start == s.size()) {
            return _endOfWord;
        }
        
        if (s[start] == '.') {
            bool found = false;
            for (int i =0; i < 26 && !found; i++) {
                if (_children[i] == nullptr) continue;
                found |= _children[i]->search(s, start+1);
            }
            return found;
        }
        
        if (_children[s[start]-'a'] == nullptr) return false;
        return _children[s[start]-'a']->search(s, start+1);
    }
};

class WordDictionary {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        root->insert(word, 0);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return root->search(word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
