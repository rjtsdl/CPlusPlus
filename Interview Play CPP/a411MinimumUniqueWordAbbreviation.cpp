//
//  a411MinimumUniqueWordAbbreviation.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string &word, string &abbr) {
        int i = 0, j = 0, m = word.length(), n = abbr.length();
        while (i < m && j < n) {
            if (word[i] == abbr[j])
                ++i, ++j;
            else if (abbr[j] == '0')
                return false;
            else if (isdigit(abbr[j])) {
                int len = 0;
                while (j < n && isdigit(abbr[j]))
                    len = len * 10 + abbr[j++] - '0';
                i += len;
            }
            else
                return false;
        }
        return i == m && j == n;
    }
    
    void helper(vector<string> &dict, string &ans, int &ansLen, string s, int num, int len, string &word, int i) {
        
        if (i == word.length()) {
            s += num ? to_string(num) : "";
            len += num ? 1 : 0;
            if (len < ansLen) {
                int valid = false;
                for (string w : dict) {
                    if (validWordAbbreviation(w, s)) {
                        valid = true;
                        break;
                    }
                }
                
                if (!valid) {
                    ansLen = len;
                    ans = s;
                }
            }
            
            return;
        }
        
        if (len == ansLen)
            return;
        
        helper(dict, ans, ansLen, s, num + 1, len, word, i + 1);
        helper(dict, ans, ansLen, s + (num ? to_string(num) : "") + word[i], 0, len + (num ? 2 : 1), word, i + 1);
    }

    string minAbbreviation(string target, vector<string>& dictionary) {
        if (target.empty())
            return "";
        
        vector<string> dict;
        for (string word : dictionary) {
            if (word.length() == target.length())
                dict.push_back(word);
        }
        
        string ans = target;
        int ansLen = target.length();
        helper(dict, ans, ansLen, "", 0, 0, target, 0);
        return ans;
    }
};
