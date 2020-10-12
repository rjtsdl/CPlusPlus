//
//  a1477FindTwoNonoverlappingSubarraysEachWithTargetSum.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/12/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> pre(n,n),suf(n,n);
        unordered_map<int,int > m;
        int curr=0;
        for(int i=0;i<n;i++){
                curr+=arr[i];
                if(curr==target){
                        if(i+1<n)
                                pre[i+1]=min(pre[i+1],i+1);
                        suf[0]=min(suf[0],i+1);
                }
                if(m.count(curr-target)){
                        int it=m[curr-target];
                        if(i+1<n)
                                pre[i+1]=min(pre[i+1],i-it);
                        if(it+1<n)
                        suf[it+1]=min(suf[it+1],i-it);
                }
                m[curr]=i;
                
        }
        int mn=pre[0];
        for(int i=0;i<n;i++){
                mn=min(pre[i],mn);
                pre[i]=mn;
        }
        mn=suf[n-1];
        for(int i=n-2;i>=0;i--){
                mn=min(mn,suf[i]);
                suf[i]=mn;
        }
        int ans=2*n;
        for(int i=0;i<n;i++){
                ans=min(pre[i]+suf[i],ans);
        }
        if(ans>n)
                return -1;
        return ans;
    }
};
