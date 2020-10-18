//
//  a839SimilarStringGroups.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
private:
    int numComponents;
    vector<int> root;
    vector<long long> sz;
    int find(int& a)
    {
        if(a==root[a])
            return a;
        return root[a] = find(root[a]);
    }
    void merge(int& a, int& b)
    {
        int r1 = find(a), r2 = find(b);
        if(r1==r2)  return;
        if(sz[r1]<sz[r2])
            swap(r1,r2);
        root[r2] = r1;
        sz[r1]+=sz[r2];
        numComponents--;
    }
    bool checkConnected(string& a, string& b)
    {
        int n = 0;
        for(int i=0;i<a.size();i++)
            if(a[i]!=b[i])
                n++;
        return n<=2;
    }
public:
    int numSimilarGroups(vector<string>& A) {
        sz.resize(A.size(),1);
        root.resize(A.size());
        for(int i=0;i<A.size();i++)
            root[i] = i;
        numComponents = A.size();
        for(int i=0;i<A.size();i++)
            for(int j=i+1;j<A.size();j++)
                if(checkConnected(A[i],A[j]))
                    merge(i,j);
        
        return numComponents;
    }
};
