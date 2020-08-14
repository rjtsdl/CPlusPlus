//
//  a773SlidingPuzzle.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    /*
    string toString(vector<vector<int>> &board) {
        string res = "";
        for (auto v: board) {
            for (auto i : v) {
                res += ('0'+i);
            }
        }
        return res;
    }
    
    vector<vector<int>> toVector(string& board)
    {
        vector<vector<int>> res(2, vector<int>(3, 0));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                res[i][j] = (int)(board[j+i*3]-'0');
            }
        }
        return res;
    }
    
    vector<string> getAdjVertex(string& board) {
        int p =0;
        while(board[p] != '0') {
            p++;
        }
        int i = p/3, j = p%3;
        
        vector<vector<int>> v = toVector(board);
        vector<string> res;
        
        if (j-1 >=0) {
            v[i][j] = v[i][j-1];
            v[i][j-1] = 0;
            res.push_back(toString(v));
            v[i][j-1] = v[i][j];
            v[i][j] = 0;
        }
        
        if (i-1 >=0) {
            v[i][j] = v[i-1][j];
            v[i-1][j] = 0;
            res.push_back(toString(v));
            v[i-1][j] = v[i][j];
            v[i][j] = 0;
        }
        
        if (j+1 < 3 ) {
            v[i][j] = v[i][j+1];
            v[i][j+1] = 0;
            res.push_back(toString(v));
            v[i][j+1] = v[i][j];
            v[i][j] = 0;
        }
        
        if (i+1 < 2) {
            v[i][j] = v[i+1][j];
            v[i+1][j] = 0;
            res.push_back(toString(v));
            v[i+1][j] = v[i][j];
            v[i][j] = 0;
        }
        
        return res;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        
        string target = toString(board);
        if (target == "123450") {
            return 0;
        }
        
        unordered_set<string> visited;
        int step = 0;
        vector<string> level(1, "123450");
        vector<string> nextLevel;
        
        while (!level.empty() || !nextLevel.empty()) {
            if (level.empty()) {
                step += 1;
                level = nextLevel;
                nextLevel = vector<string>();
            } else {
                string t = *level.rbegin();
                level.pop_back();
                
                if (t == target) {
                    return step;
                }
                
                visited.insert(t);
                auto neighbors = getAdjVertex(t);
                for (string s: neighbors) {
                    if (visited.find(s) != visited.end()) {
                        continue;
                    }
                    visited.insert(s);
                    nextLevel.push_back(s);
                }
            }
        }
        
        return -1;
    }*/
    
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string> seen;
        queue<string> todo;
        vector<vector<int>> moves = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        string str;
        int step=-1;

        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
                str+=to_string(board[i][j]);

        todo.push(str);
        while(todo.size()){
            step++;
            int n=todo.size();
            while(n--){
                auto& cur=todo.front();
                if(cur=="123450")
                    return step;
                seen.insert(cur);
                int pos=cur.find('0');
                for(auto i: moves[pos]){
                    swap(cur[pos], cur[i]);
                    if(seen.count(cur)==0)
                        todo.push(cur);
                    swap(cur[pos], cur[i]);
                }
                todo.pop();
            }
        }
        return -1;
    }
};
