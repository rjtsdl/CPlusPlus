//
//  a1087BraceExpansion.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/23/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void util(vector<string> &a, int index, int n, string temp, vector<string> &res){
        if(index == n){
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < a[index].length(); i++)
            util(a, index + 1, n, temp + a[index][i], res);
    }
    
    vector<string> expand(string s) {
        vector<string> a;
        int n = s.length(), i = 0;
        while(i < n){
            if(s[i] == '{'){
                i++;
                string letters = "";
                while(i < n && s[i] != '}'){
                    if(isalpha(s[i])) letters += s[i];
                    i++;
                }
                sort(letters.begin(), letters.end());
                a.push_back(letters);
            } else a.push_back(string(1, s[i]));
            i++;
        }
        vector<string> res;
        util(a, 0, a.size(), "", res);
        return res;
    }
};
