//
//  a1274NumberOfShipsInARectangle.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/26/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    class Sea {
       public:
         bool hasShips(vector<int> topRight, vector<int> bottomLeft);
    };
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        return count(sea, bottomLeft[0], topRight[0], bottomLeft[1], topRight[1]+1);
    }
    
    int count(Sea& sea, int x1, int x2, int y1, int y2) {
        if(x1 > x2 || y1 > y2) return 0;
        if(!sea.hasShips({x2,y2}, {x1,y1})) return 0;
        if(x1==x2 && y1==y2) return 1;
        int x3 = (x1+x2)/2, y3 = (y1+y2)/2;
        return count(sea, x1, x3, y1, y3) + count(sea, x3+1, x2, y1, y3)
            + count(sea, x1, x3, y3+1, y2) + count(sea, x3+1, x2, y3+1, y2);
    }
};
