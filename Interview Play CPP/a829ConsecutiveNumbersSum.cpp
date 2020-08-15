//
//  a829ConsecutiveNumbersSum.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include "math.h"

using namespace std;

class Solution {
public:
    
    int maxnum (long num){
        return (int)((sqrt(1+(8*num))-1)/2);
    }
    int consecutiveNumbersSum(int num) {
        int maxConsec=maxnum(num);
        int res=0;
        for(int i=2;i<=maxConsec;i++){
            if(i%2==1&&num%i==0){res++;}
            else if(i%2==0&&num%i==i/2){res++;}
        }
        return res+1;
    }
};
