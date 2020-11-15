//
//  a127WordLadder.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for (string& s: wordList) {
            wordSet.insert(s);
        }
        
        unordered_set<string> visited;
        
        unordered_set<string> top;
        unordered_set<string> bottom;
        top.insert(beginWord);
        if (wordSet.find(endWord) != wordSet.end()) bottom.insert(endWord);
        int dist = 2;
        
        while (!top.empty() && !bottom.empty()) {
            vector<string> next;
            for (string s: top) {
                visited.insert(s);
                vector<string> neis = getNeighbors(s);
                for (string& n: neis) {
                    if (wordSet.find(n) != wordSet.end() && visited.find(n) == visited.end()) {
                        if (bottom.find(n) != bottom.end()) {
                            return dist;
                        }
                        next.push_back(n);
                    }
                }
            }
            dist++;
            top.clear();
            top.insert(next.begin(), next.end());
            next.clear();
            swap(top, bottom);
        }
        return 0;
    
    }
    
    vector<string> getNeighbors(string s) {
        vector<string> ret;
        for (int i =0; i < s.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != s[i]) {
                    string n = s;
                    n[i] = c;
                    ret.push_back(n);
                }
            }
        }
        return ret;
    }
};
