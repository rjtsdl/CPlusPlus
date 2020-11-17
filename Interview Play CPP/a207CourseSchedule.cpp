//
//  a207CourseSchedule.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // detect cycle
        vector<bool> visited(numCourses, false);
        vector<bool> inStack(numCourses, false);
        
        vector<vector<int>> adj(numCourses);
        for (vector<int> e : prerequisites) {
            adj[e[0]].push_back(e[1]);
        }
        
        
        for (int i =0; i < numCourses; i++) {
            if (dfs(adj, visited, inStack, i)) return false;
        }
        
        return true;
    }
    
    bool dfs(vector<vector<int>>& adj,
             vector<bool>& visited,
             vector<bool> inStack,
             int start) {
        if (visited[start]) return false;
        if (inStack[start]) return true;
        inStack[start] = true;
        
        for (int d: adj[start]) {
            if (dfs(adj, visited, inStack, d)) return true;
        }
        
        visited[start] = true;
        return false;
    }
};
