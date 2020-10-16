//
//  a745PrefixandSuffixSearch.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Trie {
private:
    set<int> indexes;
    map<char, Trie*> children;
public:
    void insert(string s, int index) {
        indexes.insert(index);
        if (s.empty()) return;
        if (children[s[0]] == nullptr) {
            children[s[0]] = new Trie();
        }
        
        children[s[0]]->insert(s.substr(1), index);
    }
    
    int find(string s) {
        if (indexes.empty()) return -1;
        if (s.empty()) {
            return *(indexes.rbegin());
        }
        return children[s[0]]->find(s.substr(1));
    }
};

class WordFilter {
private:
    Trie* root;
    vector<string> genSuffixWrappedWords(string word) {
        vector<string> ret;
        for (int i = 0; i < word.size(); i++) {
            ret.push_back(word.substr(i)+"#" + word);
        }
        return ret;
    }
    
public:
    WordFilter(vector<string>& words) {
        root = new Trie();
        for (int i = 0; i < words.size(); i++) {
            vector<string> gen = genSuffixWrappedWords(words[i]);
            for (string& g: gen) {
                root->insert(g, i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return root->find(suffix+"#"+prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
