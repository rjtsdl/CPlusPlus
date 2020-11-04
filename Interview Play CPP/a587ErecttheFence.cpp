//
//  a587ErecttheFence.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/4/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    #define ll long long int
    static bool cmp(vector<int> &v1,vector<int> &v2){
        if(v1[0]!=v2[0])
            return v1[0]<v2[0];
        return v1[1]<v2[1];
    }
    
    static ll crossProduct(vector<int> &P,vector<int> &Q,vector<int> &R){
        return ((Q[0]-P[0])*(R[1]-Q[1]))-((Q[1]-P[1])*(R[0]-Q[0]));
    }
                
    vector<vector<int>> outerTrees(vector<vector<int>>& p) {
        int n=p.size();
        if(p.size()<=3) return p;
        
        sort(p.begin(),p.end(),cmp);
        
        int k=0,t;
        vector<vector<int> >ans;
        for(int i=0;i<n;++i){
            while(ans.size()>1 && crossProduct(ans[ans.size()-2],ans[ans.size()-1],p[i])<0){
                ans.pop_back();
            }
            ans.push_back(p[i]);
        }
        t=ans.size()+1;
        for(int i=n-1;i>=0;--i){
            while(ans.size()>1 && crossProduct(ans[ans.size()-2],ans[ans.size()-1],p[i])<0)
                ans.pop_back();
            ans.push_back(p[i]);
        }
        set<vector<int> >s;
        for(int i=0;i<ans.size();++i)
            s.insert(ans[i]);
        ans.clear();
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
        
    }
};
