//
//  a833FindAndReplaceinString.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/7/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
       // map indices to source-target index pairs in descending order
       map<int,int, greater<int>> m;
       for (int i = 0, n = indexes.size(); i < n; ++i) m[indexes[i]] = i;
       for (auto& p : m) {
           int sidx = p.first;
           const string& source = sources[p.second], target = targets[p.second];
           if (equal(begin(source), end(source), begin(S)+sidx))
               S.replace(sidx, source.size(), target);
       }
       return S;
   }
};
