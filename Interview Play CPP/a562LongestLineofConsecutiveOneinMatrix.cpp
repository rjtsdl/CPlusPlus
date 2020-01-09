//
//  a562LongestLineofConsecutiveOneinMatrix.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/9/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
private:
    struct cell{
        int up, left, dia, antiDia;
        cell():up(0), left(0), dia(0), antiDia(0){}
        cell(int up, int left, int dia, int antiDia):up(up), left(left), dia(dia), antiDia(antiDia){}
        bool emptyCell(){
            return this->up == 0;
        }
        int max(){
            return std::max(this->up, std::max(this->left, std::max(this->dia, this->antiDia)));
        }
    };
public:
    int longestLine(vector<vector<int>>& M) {
        int res= 0;
        if(M.empty()){
            return res;
        }
        vector<vector<cell>> dp(M.size()+1, vector<cell>(M[0].size()+1));
        for(int i = 0; i < M.size(); ++i){
            for(int j = 0; j < M[0].size(); ++j){
                if(M[i][j] == 1){
                    dp[i+1][j+1] = cell(1,1,1,1);
                }
            }
        }
        for(int i = 1; i <=M.size(); ++i){
            for(int j = 1; j <= M[0].size(); ++j){
                if(dp[i][j].emptyCell()){
                    continue;
                }
                dp[i][j].up += dp[i-1][j].up;
                dp[i][j].left += dp[i][j-1].left;
                dp[i][j].dia += dp[i-1][j-1].dia;
                if(j+1<=M[0].size()) dp[i][j].antiDia += dp[i-1][j+1].antiDia;
                res = max(res, dp[i][j].max());
            }
        }
        
        return res;
    }
};
