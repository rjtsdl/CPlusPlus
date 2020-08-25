//
//  a815BusRoutes.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/25/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <list>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S==T) return 0;
        int N = routes.size();

        vector<vector<int>> graph;
        for (int i = 0; i < N; ++i) {
            sort(routes[i].begin(), routes[i].end());
            graph.push_back({});
        }
        set<int> seen;
        set<int> targets;
        queue<pair<int, int>> q;

        // Build the graph.  Two buses are connected if
        // they share at least one bus stop.
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j)
                if (intersect(routes[i], routes[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }

        // Initialize seen, queue, targets.
        // seen represents whether a node has ever been enqueued to queue.
        // queue handles our breadth first search.
        // targets is the set of goal states we have.
        for (int i = 0; i < N; ++i) {
            if (find(routes[i].begin(), routes[i].end(), S) != routes[i].end()) {
                seen.insert(i);
                q.push(make_pair(i, 0));
            }
            
            if (find(routes[i].begin(), routes[i].end(), T) != routes[i].end()) {
                targets.insert(i);
            }
        }

        while (!q.empty()) {
            auto info = q.front(); q.pop();
            int node = info.first, depth = info.second;
            if (targets.count(node)) return depth+1;
            for (int nei: graph[node]) {
                if (!seen.count(nei)) {
                    seen.insert(nei);
                    q.push(make_pair(nei, depth+1));
                }
            }
        }

        return -1;
    }
    
    bool intersect(vector<int> A, vector<int> B) {
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            if (A[i] == B[j]) return true;
            if (A[i] < B[j]) i++; else j++;
        }
        return false;
    }
};
