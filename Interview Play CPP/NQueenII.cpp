//
//  NQueenII.cpp
//  Interview Play CPP
//
//  Created by Jingtao on 2/12/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<std::pair<int, int>> queens;
        int totalCount = 0;
        //goAhead(queens, totalCount, n, 0, 0);
        
        int x = 0;
        int y = 0;
        while (queens.size() >0 || (x != n && y != n)) {
            if (queens.size() == n) {
                totalCount++;
            }
            if (y == n || x == n) {
                if (queens.size() > 0) {
                    std::pair<int, int> lastOne = queens[queens.size() -1];
                    queens.pop_back();
                    x = lastOne.first;
                    y = lastOne.second + 1;
                    continue;
                }
                else
                {
                    break;;
                }
            }
            
            bool isFitInto = true;
            for (auto& queen : queens) {
                if (queen.first == x || queen.second == y || x - queen.first == y - queen.second
                    || x - queen.first == queen.second - y ) {
                    isFitInto = false;
                    break;
                }
            }
            
            if (isFitInto) {
                queens.push_back(std::make_pair(x, y));
                x = x +1;
                y = 0;
                continue;
            }
            else
            {
                x =x ;
                y = y+1;
                continue;
            }
            
        }
        return totalCount;
        
    }
    /* Same logic, but, don't use recursive
    void goAhead(vector<std::pair<int, int>>& queens, int& totalCount, int n, int x, int y)
    {
        if (queens.size() == n) {
            totalCount++;
        }

        if (y == n || x == n) {
            if (queens.size() > 0) {
                std::pair<int, int> lastOne = queens[queens.size() -1];
                queens.pop_back();
                goAhead(queens, totalCount, n, lastOne.first, lastOne.second+1);
                return;
            }
            else
            {
                return;
            }
        }
        
        bool isFitInto = true;
        for (auto& queen : queens) {
            if (queen.first == x || queen.second == y || x - queen.first == y - queen.second
                || x - queen.first == queen.second - y ) {
                isFitInto = false;
                break;
            }
        }
        
        if (isFitInto) {
            queens.push_back(std::make_pair(x, y));
            goAhead(queens, totalCount, n, x+1, 0);
            return;
        }
        else
        {
            goAhead(queens, totalCount, n, x, y+1);
            return;
        }
        
        
    }
     */
};
/*
int main()
{
    Solution sol;
    cout<<sol.totalNQueens(9);
}
 */
