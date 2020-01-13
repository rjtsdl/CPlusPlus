//
//  a1316DistinctEchoSubstrings.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/13/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<string> results;
        for(int s=0; s <text.size();++s) {
            vector<int> kmp_table(text.size()-s, 0);
            int i = 1;
            int j = 0;
            while (i < kmp_table.size()) {
                if(text[s+i] == text[s+j]) {
                    j++;
                    kmp_table[i++] = j;
                    
                    if (i%2==1) continue;
                    if ((i/2)%(i-j) == 0) {
                        results.insert(text.substr(s, i));
                    }
                } else if (j==0) {
                    i++;
                } else {
                    j = kmp_table[j-1];
                }
            }
        }
        return (int)results.size();
    }
};
