//
//  a737SentenceSimilarityII.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int f(vector<int>& a, int i) {
        if(a[i] == i) {
            return i;
        }
        return a[i] = f(a,a[i]);
    }
    void combine(vector<int>& a, int i, int j) {
        int i_ = f(a,i);
        int j_ = f(a,j);
        a[i_] = j_;
    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if(words1.size() != words2.size()){
            return false;
        }
        int i = 0;
        unordered_map<string,int> m;
        for(int j = 0;j<words1.size();j++) {
            auto& x = words1[j];
            auto& y = words2[j];
            if(!m.count(x)) {
                m[x] = i++;
            }
            if(!m.count(y)) {
                m[y] = i++;
            }
        }
        for(auto& p : pairs) {
            auto& x = p[0];
            auto& y = p[1];
            if(!m.count(x)) {
                m[x] = i++;
            }
            if(!m.count(y)) {
                m[y] = i++;
            }
        }
        vector<int> a(i);
        for(i = 0;i<a.size();i++) {
            a[i] = i;
        }
        for(auto& p : pairs) {
            auto& x = p[0];
            auto& y = p[1];
            combine(a,m[x],m[y]);
        }
        for(i = 0;i<words1.size();i++) {
            if(f(a,m[words1[i]]) == f(a,m[words2[i]])) {
                continue;
            }
            return false;
        }
        return true;
    }
};
