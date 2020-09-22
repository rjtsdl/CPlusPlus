//
//  a1061LexicographicallySmallestEquivalentString.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/22/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    array<int, 26> parent;
    int find(int c){
        if (parent[c] != c){
            parent[c] = find(parent[c]);
        }
        return parent[c];
    }
    
    void Union(int x, int y){
        int p1 = find(x);
        int p2 = find(y);
        if (p1 > p2){
            parent[p1]=p2;
        }else{
            parent[p2]=p1;
        }
    }

    string smallestEquivalentString(string A, string B, string S) {
        iota(parent.begin(), parent.end(), 0);
        for (int i = 0; i < A.size(); ++i){
            Union(A[i]-'a', B[i]-'a');
        }
        for (auto & c:S){
            c=find(c-'a')+'a';
        }
        return S;
    }
};
