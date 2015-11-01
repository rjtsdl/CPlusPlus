//
//  PalindromeNumber.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/1/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
class PalindromeNumber {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int orig_x = x;
        long rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return (long)orig_x == rev;
        
    }
};