//
//  a953VerifyingAnAlienDictionary.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/12/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int* orderMap = new int[order.size()];
        for (int i=0 ; i < order.size(); ++i) {
            orderMap[order[i]-'a'] = i;
        }
        
        for(int i =0 ; i < words.size()-1; ++i) {
            int j = 0;
            while (j < words[i].size() && j < words[i+1].size()) {
                if (words[i][j] == words[i+1][j]) j++;
                else if (orderMap[words[i][j]-'a'] > orderMap[words[i+1][j]-'a']) {
                    return false;
                } else {
                    break;
                }
            }
            
            if (words[i+1].size() != words[i].size() && j >= words[i+1].size()) {
                return false;
            }
        }
        
        return true;
        
    }
};
