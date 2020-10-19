//
//  a885SpiralMatrixIII.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        
        vector<vector<int>> ret;
        int step = 0;
        ret.push_back({r0, c0});
        
        while (ret.size() < R*C) {
            step++;
            for (int i = 0; i < step; i++) {
                c0++;
                if (r0 >= 0 && r0 < R && c0 >=0 && c0 < C) {
                    ret.push_back({r0, c0});
                    if (ret.size() >= R*C) return ret;
                }
                
            }
            
            for (int i = 0; i < step; i++) {
                r0++;
                if (r0 >= 0 && r0 < R && c0 >=0 && c0 < C) {
                    ret.push_back({r0, c0});
                    if (ret.size() >= R*C) return ret;
                }
                
            }
            step++;
            
            for (int i = 0; i < step; i++) {
                c0--;
                if (r0 >= 0 && r0 < R && c0 >=0 && c0 < C) {
                    ret.push_back({r0, c0});
                    if (ret.size() >= R*C) return ret;
                }
                
            }
            
            for (int i = 0; i < step; i++) {
                r0--;
                if (r0 >= 0 && r0 < R && c0 >=0 && c0 < C) {
                    ret.push_back({r0, c0});
                    if (ret.size() >= R*C) return ret;
                }
                
            }
        }
        
        return ret;
        
        
    }
};
