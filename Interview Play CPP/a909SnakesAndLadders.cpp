//
//  a909SnakesAndLadders.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        unordered_map<int, int> dist;
        dist[1] = 0;
        queue<int> queue;
        queue.push(1);

        while (!queue.empty()) {
            int s = queue.front();
            queue.pop();
            if (s == N*N) return dist[s];

            for (int s2 = s+1; s2 <= min(s+6, N*N); ++s2) {
                auto cd = BousToCard(s2, N);
                int r = cd[0];
                int c = cd[1];
                int s2Final = board[r][c] == -1 ? s2 : board[r][c];
                if (!dist.count(s2Final)) {
                    dist[s2Final] = dist[s] + 1;
                    queue.push(s2Final);
                }
            }
        }
        return -1;
    }
    
    vector<int> BousToCard(int b, int N) {
        int r = N-(b-1)/N -1;
        int c = (N-r)%2 ? (b-1)%N : N-(b-1)%N-1;
        return {r, c};
        
        
    }
    
    int CardToBous(vector<int> card, int N) {
        int r = card[0];
        int c = card[1];
        return (N-r-1)*N + ((N-r-1)%2 ? N-c : c+1);
    }
};

/*
int main() {
    vector<vector<int>> testCases = {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}};
    Solution* sol = new Solution();
    sol->snakesAndLadders(testCases);
    return 0;
}
*/
