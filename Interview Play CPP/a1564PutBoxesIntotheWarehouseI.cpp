//
//  a1564PutBoxesIntotheWarehouseI.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse, int result = 0) {
        std::sort(boxes.begin(), boxes.end());
        for (int i = boxes.size() - 1; i >=0 && result < warehouse.size(); --i)
            if(boxes[i] <= warehouse[result])
                ++result;
        return result;
    }
};
