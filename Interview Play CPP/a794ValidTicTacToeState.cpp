//
//  a794ValidTicTacToeState.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/7/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x_count = 0;
        int o_count = 0;
        bool x_won = false;
        bool y_won = false;
        int arr[][3] = {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}};
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<3; j++)
            {
                char ch2 = board.at(i).at(j);
                if(ch2 == 'X')
                {
                    x_count++;
                    arr[i][j] = 1;
                }
                else if(ch2 == 'O'){
                    o_count++;
                    arr[i][j] = 0;
                }
            }
        }
        for(int i=0; i<3; i++)
        {
            if(arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) {
                if(arr[i][0] == 1) {
                    x_won = true;
                } else if(arr[i][0] == 0) {
                    y_won = true;
                }
                break;
            }
            
            if(arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]) {
                if(arr[0][i] == 1) {
                    x_won = true;
                } else if(arr[0][i] == 0) {
                    y_won = true;
                }
                break;
            }
        }
        
        if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
            if(arr[0][0] == 1) {
                x_won = true;
            } else if(arr[0][0] == 0) {
                y_won = true;
            }
        }
        
        if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
            if(arr[0][2] == 1) {
                x_won = true;
            } else if(arr[0][2] == 0) {
                y_won = true;
            }
        }
                
        if(x_won && y_won) {
            return false;
        }
        
        if(x_won && x_count-1!=o_count)
            return false;
        
        if(y_won && o_count != x_count)
            return false;
        
        if(x_count - o_count > 1 || x_count - o_count < 0) {
            return false;
        }
        return true;
    }
};
