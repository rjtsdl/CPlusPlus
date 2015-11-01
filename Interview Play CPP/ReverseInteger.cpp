//
//  ReverseInteger.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/1/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

class ReverseInteger
{
public:
    int reverse(int x) {
        bool positive = (x >= 0);
        x = abs(x);
        
        long ret = 0;
        
        while (x > 0) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        
        if (!positive) {
            ret = -ret;
        }
        
        // Comment, always think about the overflow case, for such an idiot question
        // int 4 bytes, long 8 bytes
        if (ret > INT32_MAX || ret < INT32_MIN) {
            return 0;
        }
        return (int)ret;
        
    }
};
