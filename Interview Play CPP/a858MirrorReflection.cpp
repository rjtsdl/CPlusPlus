//
//  a858MirrorReflection.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g = gcd(p, q);
        p /= g; p %= 2;
        q /= g; q %= 2;

        if (p == 1 && q == 1) return 1;
        return p == 1 ? 0 : 2;
        
    }
    
    int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};
