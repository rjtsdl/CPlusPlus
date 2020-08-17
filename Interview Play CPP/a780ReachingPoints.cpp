//
//  a780ReachingPoints.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx<sx || ty<sy) return false;
        if(tx==sx)
            return (ty-sy)%sx==0;
        if(ty==sy)
            return (tx-sx)%sy==0;
        if(tx>ty)
            return reachingPoints(sx,sy,tx-ty,ty);
        else
            return reachingPoints(sx,sy,tx,ty-tx);
    }
};
