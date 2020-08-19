//
//  a898BitwiseOrsOfSubarrays.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> s;
        for(int i=0;i<A.size();i++){
            int j=i-1;
            int x=0,y=A[i];
            s.insert(y);
            while(j>=0 and x!=y){
                x|=A[j];
                y|=A[j];
                s.insert(y);
                j--;
            }
        }
        return s.size();
    }
};
