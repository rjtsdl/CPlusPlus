//
//  a1166DesignFileSystem.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/7/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    TrieNode(int val_) {
        val = val_;
    }
    unordered_map<string, TrieNode*> next;
    int val;
};

class Trie {
public:
    Trie() {
        root = new TrieNode(-1);
    }
    bool insert(const vector<string>& path, int val) {
        TrieNode* cur = root;
        int n = path.size();
        for (int i = 0; i < n - 1; i++) {
            if (!cur->next.count(path[i]))
                return false;
            cur = cur->next[path[i]];
        }
        if (cur->next.count(path[n - 1]))
            return false;
        cur->next[path[n - 1]] = new TrieNode(val);
        return true;
    }
    int get(const vector<string>& path) {
        TrieNode* cur = root;
        for (string p : path) {
            if (!cur->next.count(p))
                return -1;
            cur = cur->next[p];
        }
        return cur->val;
    }
private:
    TrieNode* root;
};

class FileSystem {
public:

    FileSystem() {
        
    }
    
    bool createPath(string path, int value) {
        return trie.insert(split(path), value);
    }
    
    int get(string path) {
        return trie.get(split(path));
    }
private:
    vector<string> split(string path) {
        vector<string> res;
        int pre = 1;
        for (int i = 1; i <= path.size(); i++) {
            if (path[i] == '/' || i == path.size()) {
                string folder = path.substr(pre, i - pre);
                res.push_back(folder);
                pre = i + 1;
            }
        }
        return res;
    }
    Trie trie;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
