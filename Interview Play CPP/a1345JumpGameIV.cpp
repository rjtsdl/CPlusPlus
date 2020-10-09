//
//  a1345JumpGameIV.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/9/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int, queue<int> > mp;
        for(int i=0; i<n; i++) mp[arr[i]].push(i);
        queue<int> q;
        vector<int> dist(n, -1);
        dist[0]=0;
        q.push(0);
        while(!q.empty()){
            int i=q.front(); q.pop();
            if(i==n-1) break;
            if(i-1>=0 && dist[i-1]==-1){
                dist[i-1]=1+dist[i];
                q.push(i-1);
            }
            if(i+1<n && dist[i+1]==-1){
                dist[i+1]=1+dist[i];
                q.push(i+1);
            }
            while(!mp[arr[i]].empty()){
                int j=mp[arr[i]].front();
                mp[arr[i]].pop();
                if(dist[j]==-1){
                    dist[j]=dist[i]+1;
                    q.push(j);
                }
            }
        }
        return dist[n-1];
    }
};
