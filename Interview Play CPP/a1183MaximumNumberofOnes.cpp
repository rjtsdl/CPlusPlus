//
//  a1183MaximumNumberofOnes.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/25/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>


class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        // One count at various positions in first sub square
        vector<int> onesCount;
        
        onesCount.reserve(sideLength * sideLength);
        
        // Put one at (i, j) and all positions sideLength apart in x and y dirs
        for (int i = 0; i < sideLength; ++i) {
            for (int j = 0; j < sideLength; ++j) {
                int r = (width - i + sideLength -1)/sideLength;
                int c = (height - j + sideLength -1)/sideLength;

                onesCount.push_back(r * c);
            }
        }
        
        // Select max one postions. Note that this will not violate max ones constraint in any square of size
        // sideLength * sideLength anywhere in matrix
        auto start = onesCount.begin() + onesCount.size() - maxOnes;
        
        nth_element(onesCount.begin(), start, onesCount.end());;
        
        return accumulate(start, onesCount.end(), 0);
    }
};
