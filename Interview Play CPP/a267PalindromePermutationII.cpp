//
//  a267PalindromePermutationII.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        map<char,int> M;
        vector<string> sol;
        int n = s.length();
        for(int i = 0; i < n; i++)
            M[s[i]]++;
        int odd = 0;
        for(auto a : M)
        {
            if(a.second % 2)
                odd++;
        }
        if(odd > 1)
            return {};
        string str = "";
        string och = "";
        for(auto a : M)
        {
            if(a.second % 2 == 0)
                str += string(a.second / 2, a.first);
            if(a.second % 2)
            {
                str += string( (a.second - 1) / 2,a.first);
                och = string(1, a.first);
            }
        }
        string strr = str;
        reverse(strr.begin(), strr.end());
        sol.push_back(str + och +strr);
        while(next_permutation(str.begin(),
                           str.end()))
        {
            strr = str;
            reverse(strr.begin(), strr.end());
            sol.push_back(str + och +strr);
        }
        vector<string> sol1;
        sol1.push_back(sol[0]);
        for(int  i = 0; i < sol.size(); i++)
        {
            if(sol1[sol1.size() - 1] != sol[i])
                sol1.push_back(sol[i]);
        }
        return sol1;
        
    }

};
