//
//  a66PlusOne.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/13/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i =digits.size()-1; i >= 0; i--) {
            if (!carry) break;
            int temp = digits[i] + carry;
            carry =temp / 10;
            digits[i] = temp %10;
        }
        
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};
