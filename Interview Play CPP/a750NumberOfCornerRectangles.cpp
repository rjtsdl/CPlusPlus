//
//  a750NumberOfCornerRectangles.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    int m, n;
        
    int countCornerRectangles(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> numOne(m);
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]==1) numOne[i].push_back(j);
            }
        }
        int total = 0;
        for (int i=0; i<m; i++){
            for (int j=i+1; j<m; j++){
                int temp = check(numOne[i], numOne[j]);
                if (temp>=2){
                    total += temp*(temp-1)/2;
                }
            }
        }
        return total;
    }
    
    int check(vector<int> a, vector<int> b){
        int i=0, j=0, total=0;
        while (i<a.size() && j<b.size()){
            if (a[i]==b[j]) {total++; i++; j++;}
            else if (a[i]<b[j]) i++;
            else j++;
        }
        return total;
    }
};
