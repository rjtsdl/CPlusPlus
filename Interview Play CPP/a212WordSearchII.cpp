//
//  a212WordSearchII.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
    
    class TrieNode {
    public:
        vector<TrieNode*> _children;
        bool _endOfWord;
    
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
            
            if (_children[s[start]-'a'] == nullptr) return false;
            return _children[s[start]-'a']->search(s, start+1);
        }
    };
    
    TrieNode* root;
    TrieNode* cur;
    int m;
    int n;
    vector<vector<bool>> path;
    vector<vector<char>> board;
    vector<int> directions;
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (string& s: words) {
            root->insert(s, 0);
        }
        
        cur = root;
        
        m = board.size();
        n = board[0].size();
        path = vector<vector<bool>>(m, vector<bool>(n, false));
        directions = {-1,0,1,0,-1};
        
        vector<string> ret;
        
        for (int i = 0; i < m; i++) {
            for (int j =0; j < n; j++) {
                backtracking(i, j, ret, "", board);
            }
        }
        return ret;
    }
    
    void backtracking(int i, int j, vector<string>& ret, string prefix, vector<vector<char>>& board) {
        if (cur == nullptr || cur->_children[board[i][j]-'a'] == nullptr) return;
        TrieNode * cp = cur;
        cur = cur->_children[board[i][j]-'a'];
        path[i][j] = true;
        if (cur->_endOfWord) {
            ret.push_back(prefix + board[i][j]);
            cur->_endOfWord = false;
            
        };
        
        for (int k =0; k< 4; k++) {
            if (i+directions[k] >=0 && i+directions[k] < m &&
                j+directions[k+1] >=0 && j+directions[k+1] < n &&
                !path[i+directions[k]][j+directions[k+1]]) {
                backtracking(i+directions[k], j+directions[k+1], ret, prefix + board[i][j], board);
            }
        }
        
        path[i][j] = false;
        cur = cp;
    }
    
    
};
