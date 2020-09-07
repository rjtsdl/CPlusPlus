//
//  a777SwapAdjacentinLRString.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/6/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canTransform(string original, string resultant) {
        if(original.size()!=resultant.size())
            return false;
        vector<pair<char,int>> a,b;
        for(int i=0;i<original.length();i++)
        {
            if(original[i]=='L'||original[i]=='R')
                a.push_back({original[i],i});
            if(resultant[i]=='L'||resultant[i]=='R')
                b.push_back({resultant[i],i});
        }
        if(a.size()!=b.size())
            return false;
        for(int i=0;i<a.size();i++)
        {
            
            if(a[i].first!=b[i].first)
               return false;
            if(a[i].first=='R'&&a[i].second>b[i].second)
                return false;
            if(a[i].first=='L'&&a[i].second<b[i].second)
                return false;
        }
        return true;
        
    }
};
