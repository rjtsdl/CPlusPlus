//
//  Atoi.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 14/12/8.
//  Copyright (c) 2014年 Jingtao Ren. All rights reserved.
//

#include <iostream>

class Atoi {
public:
    int atoi(const char *str) {
        const char* iter = str;
        //Discard space
        while (*iter == ' ') {
            iter++;
        }
        
        //Check sign
        int mul = 1;
        if(*iter == '+')
        {
            iter++;
        }else if (*iter == '-')
        {
            mul = -1;
            iter++;
        }
        else
        {
            //Nothing to do
        }
        
        //Get sum
        long long sum = 0;
        while (*iter!='\0') {
            if (*iter <'0' ||*iter > '9') {
                break;
            }
            sum = sum*10 + (int)(*iter - '0');
            if(mul > 0)
            {
                if (sum >= INT_MAX)
                {
                    return INT_MAX;
                }
            }
            else
            {
                if (sum -1 >= INT_MAX)
                    return INT_MIN;
            }
            iter++;
            
        }
        return (int)sum*mul;
    
    }
};