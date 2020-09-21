//
//  a702SearchinaSortedArrayofUnknownSize.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>


 class ArrayReader {
   public:
     int get(int index) const;
 };

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0, r = 9999;
        while (l <= r) {
            int mid = l + (r-l)/2;
            int pivot = reader.get(mid);
            if (pivot > target) {
                r = mid -1;
            } else if (pivot == target) {
                return mid;
            } else if (pivot < target) {
                l = mid+1;
            }
        }
        
        return -1;
    }
};
