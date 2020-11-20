//
//  a394DecodeString.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int start = 0;
        return decodeString(s, start);
    }
    
    string decodeString(string& s, int& start) {
        if (start == s.size()) return "";
        int os = start;
        string ret = "";
        while (start < s.size() && isalpha(s[start])) start++;
        ret = s.substr(os, start-os);
        
        if (start < s.size() && s[start] == ']') {
            return ret;
        }
        
        
        string num = "";
        while (start < s.size() && isdigit(s[start])) {
            num += s[start++];
        }
        
        
        string in = "";
        if (start < s.size() && s[start] == '[') {
            start++;
            in = decodeString(s, start);
            start++;
        }
        
        if (!num.empty()) {
            int n = stoi(num);
            while (n > 0) {
                ret += in; n--;
            }
        }
        
        ret += decodeString(s, start);
        return ret;
    }
};
