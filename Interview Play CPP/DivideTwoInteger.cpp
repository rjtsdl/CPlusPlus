//
//  DivideTwoInteger.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/22/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

class Solution {
public:
    // Any overflow problem, use a larger container would be much easier
    int divide(int dividend, int divisor) {
        long longDividend = dividend;
        long longDivisor = divisor;
        if (longDividend == 0) {
            return 0;
        }
        if (longDivisor == 0) {
            return INT32_MAX;
        }
        
        int negative = 0;
        if (longDividend < 0) {
            negative^=1;
            longDividend = -longDividend;
        }
        if (longDivisor < 0) {
            negative^=1;
            longDivisor = -longDivisor;
        }
        
        
        long multplied = longDivisor;
        long multplier = 1;
        while (longDividend >= multplied) {
            multplied = multplied<<1;
            multplier = multplier<<1;
        }
        
        // here divisor multplied suppose to be greater than dividend
        long result = 0;
        multplied = multplied>>1;
        multplier = multplier>>1;
        while (multplied >= longDivisor) {
            if (longDividend >= multplied) {
                result += multplier;
                longDividend -=multplied;
            }
            multplied = multplied>>1;
            multplier = multplier>>1;
        }
        
        if (negative) {
            result = -result;
        }
        if (result > INT32_MAX || result < INT32_MIN) {
            return INT32_MAX;
        }
        return (int)result;
    }
};


int main()
{
    Solution sol;
    sol.divide(1, 1);
}