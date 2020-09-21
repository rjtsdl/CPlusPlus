//
//  a582KillProcess.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/20/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
   int find(vector<int>& parent, int c) {
       return (parent[c] == c) ? parent[c] : find(parent, parent[c]);
   }

   vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
       vector<int> res;
       if (pid.size() != ppid.size()) return res;
       int max = *max_element(pid.begin(), pid.end());
       vector<int> parent(max + 1);
       iota(parent.begin(), parent.end(), 0);
       for (int i = 0; i < pid.size(); i++) {
           if (pid[i] == kill) continue;
           int root1 = find(parent, pid[i]);
           int root2 = find(parent, ppid[i]);
           if (root1 != root2) parent[root1] = root2;
       }
       for (auto x : pid) {
           if (x == kill || find(parent, x) == kill) res.push_back(x);
       }
       return res;
   }
};
