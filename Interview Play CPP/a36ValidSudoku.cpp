//
//  ValidSudoku.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/28/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows;
        vector<set<char>> cols;
        vector<set<char>> squs;
        for (int i =0; i < 9; i++) {
            rows.push_back(set<char>{});
            cols.push_back(set<char>{});
            squs.push_back(set<char>{});
        }
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (rows[i].find(board[i][j]) == rows[i].end()) {
                        rows[i].insert(board[i][j]);
                    }
                    else
                    {
                        return false;
                    }
                    
                    if (cols[j].find(board[i][j]) == cols[j].end()) {
                        cols[j].insert(board[i][j]);
                    }
                    else
                    {
                        return false;
                    }
                    
                    if (squs[(i/3)*3 + j/3].find(board[i][j]) == squs[(i/3)*3 + j/3].end()) {
                        squs[(i/3)*3 + j/3].insert(board[i][j]);
                    }
                    else
                    {
                        return false;
                    }
                }
                
                
            }
        }
        return true;
    }
};