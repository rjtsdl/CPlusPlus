//
//  a616AddBoldTagInString.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/27/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<bool> test(s.size(),false);
        
        for (auto& word : dict) {
            int w_s = word.size();
            for (int i = 0; i < int(s.size())-w_s+1; ++i)
                if (s.substr(i,w_s) == word)
                    for (int j = i; j < i + w_s; ++j)
                        test[j] = true;
        }
        
        string res = "";
        for (int i = 0; i < test.size(); ++i) {
            if (test[i]) {
                if (i == 0 || !test[i-1])
                    res += "<b>";

                res.push_back(s[i]);
                
                if (i == test.size()-1 || !test[i+1])
                    res += "</b>";
                }
            else
                res.push_back(s[i]);
        }
        
        return res;
    }
};
