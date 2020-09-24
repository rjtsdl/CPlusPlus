//
//  a1136ParallelCourses.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/24/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<int> indegree(N);
        map<int, vector<int>> graph;
        for (vector<int>& relation: relations) {
            graph[relation[0]-1].push_back(relation[1]-1);
            indegree[relation[1]-1]++;
        }
        queue<int> q;
        for(int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        int semesters = 0;
        while (!q.empty()) {
            int size = q.size();
            while (--size >= 0) {
                count++; // if there are no loop, count will be N after topogical sorting
                int node = q.front(); q.pop();
                for (int adj: graph[node]) {
                    if (--indegree[adj] == 0) {
                        q.push(adj);
                    }
                }
            }
            semesters++;
        }
        return count == N? semesters: -1;
    }
};
