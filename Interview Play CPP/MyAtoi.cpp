//
//  MyAtoi.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/1/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;


// Too many stupid test case, which doesn't make sense at all
class MyAtoi
{
public:
    int myAtoi(string str) {
        // In case overflow, use a bigger space
        long ret = 0;
        bool isNegative = false;
        int pos = 0;
        if (str.length() == 0)
        {
            return 0;
        }
        
        while (pos < str.length()) {
            if (str[pos] == '-') {
                isNegative = true;
                ++pos;
                break;
                
            }
            else if (str[pos] == '+')
            {
                ++pos;
                break;
            }
            else if (str[pos] >= '0' && str[pos] <= '9')
            {
                // do nothing;
                break;
            }
            else
            {
                // out of consideration
                ++pos;
            }
        }
        
        while (pos < str.length()) {
            if (str[pos] > '9' || str[pos] < '0') {
                return 0;
            }
            
            ret = ret * 10 + (str[pos] - '0');
            ++pos;
        }
        
        if (isNegative) {
            ret = -ret;
        }
        
        if (ret > INT32_MAX || ret < INT32_MIN) {
            return 0;
        }
        
        return (int)ret;
    }
};
