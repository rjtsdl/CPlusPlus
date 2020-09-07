//
//  a1071GreatestCommonDivisorofStrings.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/6/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size()) {
            return gcdOfStrings(str2, str1);
        }
        
        if (str1.size() == str2.size() && str1 == str2) {
            return str1;
        }
        
        if (str1.substr(0, str2.size()) == str2) {
            return gcdOfStrings(str2, str1.substr(str2.size()));
        }
        
        return "";
        
        // or one liner
        // return (str1+str2 == str2+str1)?(str1.substr(0,gcd(str1.size(),str2.length()))):"";
        
    }
};
