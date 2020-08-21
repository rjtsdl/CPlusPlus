//
//  a1344AngleBetweenHandsOfAClock.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include "math.h"

class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;
        minutes %= 60;
        return fmin(abs(minutes * 5.5 - hour * 30), 360.0 - abs(minutes * 5.5 - hour * 30));
    }
};
