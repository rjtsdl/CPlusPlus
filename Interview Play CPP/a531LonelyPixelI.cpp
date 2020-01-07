//
//  a531LonelyPixelI.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/7/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        vector<int> row(picture.size(), 0);
        vector<int> col(picture[0].size(), 0);
        
        int count = 0;
        
        for (int i =0; i < picture.size(); ++i) {
            for (int j =0; j < picture[0].size(); ++j) {
                if (picture[i][j] == 'W')  continue;
                row[i]++;
                col[j]++;
                
                if (row[i] == 1 && col[j] == 1) {
                    count++;
                }
                
                if (row[i] == 2) {
                    count--;
                }
                
                if (col[j] == 2) {
                    count--;
                }
            }
        }
        
        return count>0 ? count:0;
        
    }
};
