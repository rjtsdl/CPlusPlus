//
//  a405ConvertaNumbertoHexadecimal.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    string fun(unsigned int num) {
        if(num<0){
            return ""+fun((UINT_MAX|(num*-1))+1);
        }
        if(num==0)return "";
        if(num%16==10)
        return fun(num/16)+'a';
        if(num%16==11)
        return fun(num/16)+'b';
        if(num%16==12)
        return fun(num/16)+'c';
        if(num%16==13)
        return fun(num/16)+'d';
        if(num%16==14)
        return fun(num/16)+'e';
        if(num%16==15)
        return fun(num/16)+'f';
        return fun(num/16)+to_string(num%16);
    }

    string toHex(unsigned int num)
    {
        if(num==0)
            return "0";
        else
            return fun(num);
    }

};
