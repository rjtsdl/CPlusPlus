//
//  a721AccountsMerge.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int find(vector<int>&p,int i)
    {
        if(p[i]==-1) return i;
        return p[i] = find(p,p[i]);
    }
    void doUnion(vector<int>&p,int i,int j)
    {
        int xp = find(p,i);
        int yp = find(p,j);
        if(xp!=yp)
            p[xp]=yp;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        int n = a.size();    // n: number of different names
        vector<int> p(n,-1);

        unordered_map<string,unordered_set<int>> m;
        
        for(int i=0;i<a.size();++i)
        {
            for(int j=1;j<a[i].size();++j)
            {
                m[a[i][j]].insert(i);    // for each mail store the names of owner
            }
        }
        unordered_map<string,unordered_set<int>>::iterator it = m.begin();
        int c=0;
        for(;it!=m.end();++it)
        {
            if(it->second.size()>1)  // if there are more than 2 owners of the mail then we merge them under onr owner
            {
                unordered_set<int>::iterator it2 = it->second.begin(),it3=it->second.begin();
                it3++;
                while(it3!=it->second.end())
                {
                    doUnion(p,*it2,*it3);
                    it2=it3;
                    it3++;
                }
            }
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;++i)
        {
            if(p[i]==-1)   // unique owners have no parents
            {
                set<string>s;   // using set to sort email lexocographically
                for(int j=1;j<a[i].size();++j)
                    s.insert(a[i][j]);
                for(int j=0;j<n;++j)
                {
                    if(find(p,j)==i)
                    {
                        for(int k=1;k<a[j].size();++k)
                            s.insert(a[j][k]);
                    }
                }
                vector<string> t(s.begin(),s.end());
                t.insert(t.begin(),a[i][0]);   // inserting owner name in the beginning
                ans.push_back(t);
            }
        }
        return ans;
    }
};
