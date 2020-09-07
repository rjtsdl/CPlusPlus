//
//  a323NumberofConnectedComponentsinanUndirectedGraph.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/7/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int find(int node,const vector<int> &parent){
        return (parent[node]==node?node:find(parent[node],parent));
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto i:edges){
            parent[find(i[1],parent)]=find(i[0],parent);
        }
        int answer=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==i) ++answer;
        }
        return answer;
    }
};
