//
//  a1059AllPathsfromSourceLeadtoDestination.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/22/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    bool DFS(vector<vector<int>> &graph, int node, int destination, vector<int>   &visited){
        
        if(graph[node].size()==0 && node != destination) // another destination node
            return false;
        
        visited[node]=1; // node under processing
        
        for(int i=0; i<graph[node].size(); i++){
            int nei = graph[node][i];
            if(visited[nei]==1)
                return false;
            if(visited[nei]==0 && !DFS(graph, nei, destination, visited))
                return false;
        }
        visited[node]=2; //processed node
        return true;
    }

    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> graph(n+1);
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> visited(n+1,0); // unprocessed Nodes
        return DFS(graph, source, destination, visited);
    }
    
};
