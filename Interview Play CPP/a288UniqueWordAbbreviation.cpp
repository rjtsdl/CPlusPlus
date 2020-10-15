//
//  a288UniqueWordAbbreviation.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/15/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <string>
#include <set>

using namespace std;

class ValidWordAbbr {
private:
    unordered_map<string, set<string>> st;
    string getAbbr(string wrd) {
        if (wrd.size() < 3) return wrd;
        return wrd[0] + to_string(wrd.size() - 2) + wrd.back();
    }
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (string& d : dictionary) {
            st[getAbbr(d)].insert(d);
        }
        
    }
    
    bool isUnique(string word) {
        return st[getAbbr(word)].size() == 0 || (st[getAbbr(word)].size() == 1 && *(st[getAbbr(word)].begin()) == word);
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
