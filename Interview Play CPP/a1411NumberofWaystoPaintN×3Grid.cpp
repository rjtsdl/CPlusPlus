//
//  a1411NumberofWaystoPaintN×3Grid.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/6/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#

class Solution {
public:
    int numOfWays(int n) {
        // 2 case of a row: 121, 123
        // 121 -> 212, 213, 232, 312, 313 => "121"pattern 3 times, "123" 2 times
        // 123-> 212, 231, 232, 312  => "121"pattern 2 times, "123" 2 times
        const long long mod = 1e9+7;
        long long a = 6, b = 6;
        while(--n){
            auto c = a*3 + b*2, d = a*2+b*2;
            a = c % mod, b = d% mod;
        }
        return (a+b)%mod;
    }
};
