//
//  FindPeakElement.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 14/12/7.
//  Copyright (c) 2014年 Jingtao Ren. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class FindPeakElement {
public:
    int findPeakElement(const vector<int> &num) {
        for( int i=0; i< num.size();)
        {
            int status = compareBothSide(num, i);
            if(status == 2)
            {
                return i;
            }
            else if (status == 1)
            {
                ++i;
            }
            else if (status == 3)
            {
                ++i;
            }
            else if (status == 4)
            {
                i+=2;
            }
            else
            {
                return -1;
            }
        }
        return -1;
    }
    
    // Based on no equality,
    // 1<2<3 1
    // 1<2>3 2
    // 1>2<3 3
    // 1>2>3 4
    int compareBothSide(const vector<int> &num, int idx)
    {
        if(idx-1< 0 || num[idx-1] < num[idx])
        {
            if (idx + 1>= num.size() || num[idx] > num[idx+1]) {
                return 2;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            if (idx + 1>= num.size() || num[idx] > num[idx+1]) {
                return 4;
            }
            else
            {
                return 3;
            }
        }
    }
};
