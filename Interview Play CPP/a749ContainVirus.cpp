//
//  a749ContainVirus.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/27/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    set<int> seen;
    vector<set<int>> regions;
    vector<set<int>> frontiers;
    vector<int> perimeters;
    vector<vector<int>> grid;
    int R, C;
    vector<int> dr{-1, 1, 0, 0};
    vector<int> dc{0, 0, -1, 1};

    void dfs(int r, int c) {
        if (!seen.count(r*C + c)) {
            seen.insert(r*C + c);
            int N = regions.size();
            regions[N - 1].insert(r*C + c);
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                    if (grid[nr][nc] == 1) {
                        dfs(nr, nc);
                    } else if (grid[nr][nc] == 0){
                        frontiers[N - 1].insert(nr*C + nc);
                        perimeters[N-1]++;
                    }
                }
            }
        }
    }
    int containVirus(vector<vector<int>>& g) {
        this->grid = g;
        this->R = g.size();
        this->C = g[0].size();

        int ans = 0;
        while (true) {
            this->seen = set<int>();
            this->regions = vector<set<int>>();
            this->frontiers = vector<set<int>>();
            this->perimeters = vector<int>();

            for (int r = 0; r < this->R; ++r) {
                for (int c = 0; c < this->C; ++c) {
                    if (grid[r][c] == 1 && !seen.count(r*C + c)) {
                        regions.push_back(set<int>());
                        frontiers.push_back(set<int>());
                        perimeters.push_back(0);
                        dfs(r, c);
                    }
                }
            }

            if (regions.empty()) break;
            int triageIndex = 0;
            for (int i = 0; i < frontiers.size(); ++i) {
                if (frontiers[triageIndex].size() < frontiers[i].size())
                    triageIndex = i;
            }
            ans += perimeters[triageIndex];

            for (int i = 0; i < regions.size(); ++i) {
                if (i == triageIndex) {
                    for (int code: regions[i])
                        grid[code / C][code % C] = -1;
                } else {
                    for (int code: regions[i]) {
                        int r = code / C, c = code % C;
                        for (int k = 0; k < 4; ++k) {
                            int nr = r + dr[k], nc = c + dc[k];
                            if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 0)
                                grid[nr][nc] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
