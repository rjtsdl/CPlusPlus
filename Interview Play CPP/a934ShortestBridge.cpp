//
//  a934ShortestBridge.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/20/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        queue<vector<int>> edges;
        bool found = false;
        for (int i =0 ;i < A.size(); i++) {
            for (int j = 0; j< A[0].size(); ++j) {
                if (A[i][j] == 1) {
                    found = true;
                    dfs(A, i, j, edges);
                    break;
                }
            }
            if (found) break;
        }
        
        int steps = 0;
        while (!edges.empty()) {
            int n= edges.size();
            for (int k = 0; k < n; k++) {
                vector<int> p = edges.front();
                edges.pop();
                
                int i = p[0];
                int j = p[1];
                /*
                cout << "steps: " << steps << endl;
                cout << "edge point: " << i << "," << j << endl;
                */
                if (i-1 >= 0) {
                    if(A[i-1][j] == 0) {
                        A[i-1][j] =2;
                        edges.push({i-1, j});
                    } else if (A[i-1][j] == 1) {
                        return steps;
                    }
                }
                
                if (i+1 < A.size()) {
                    if(A[i+1][j] == 0) {
                        A[i+1][j] =2;
                        edges.push({i+1, j});
                    } else if (A[i+1][j] == 1) {
                        return steps;
                    }
                }
                
                if (j-1 >= 0) {
                    if(A[i][j-1] == 0) {
                        A[i][j-1] =2;
                        edges.push({i, j-1});
                    } else if (A[i][j-1] == 1) {
                        return steps;
                    }
                }
                
                if (j+1 < A[0].size()) {
                    if(A[i][j+1] == 0) {
                        A[i][j+1] =2;
                        edges.push({i, j+1});
                    } else if (A[i][j+1] == 1) {
                        return steps;
                    }
                }
            }
            steps++;
        }
            
        return -1;
    }
    
    void dfs(vector<vector<int>>& A, int i, int j, queue<vector<int>>& edges) {
        bool isEdge = false;
        A[i][j] = 2;
        
        if (i-1 >= 0) {
            if(A[i-1][j] == 0) {
                isEdge = true;
            } else if (A[i-1][j] == 1) {
                dfs(A, i-1, j, edges);
            }
        }
        
        if (i+1 < A.size()) {
            if(A[i+1][j] == 0) {
                isEdge = true;
            } else if (A[i+1][j] == 1) {
                dfs(A, i+1, j, edges);
            }
        }
        
        if (j-1 >= 0) {
            if(A[i][j-1] == 0) {
                isEdge = true;
            } else if (A[i][j-1] == 1) {
                dfs(A, i, j-1, edges);
            }
        }
        
        if (j+1 < A[0].size()) {
            if(A[i][j+1] == 0) {
                isEdge = true;
            } else if (A[i][j+1] == 1) {
                dfs(A, i, j+1, edges);
            }
        }
        
        if (isEdge) {
            edges.push({i, j});
        }
    }
};
/*
int main(){
    vector<vector<int>> in{{0,1},{1,0}};
    Solution* sol = new Solution();
    int c = sol->shortestBridge(in);
    cout << "shortest path count: " << c << endl;;
    return 0;
}
 */
