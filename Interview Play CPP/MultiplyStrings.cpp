//
//  MultiplyStrings.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 1/24/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

//Careful about num and string
class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int array[num1.size() + num2.size()];
        for (auto& num: array) {
            num = 0;
        }
        for (int i = 0; i < num1.length(); ++i) {
            for (int j = 0; j < num2.length(); ++j) {
                array[i+j] += int(num1[i] - '0') * int(num2[j] - '0');
            }
        }
        for (int i = 0; i<num1.length() + num2.length(); ++i) {
            if (array[i] >= 10) {
                array[i+1] += (array[i] - array[i]%10) / 10;
                array[i] %= 10;
            }
        }
        
        string ret = "";
        for (int num: array) {
            ret.push_back(num+'0');
        }
        
        reverse(ret.begin(), ret.end());
        while (*ret.begin() == '0' && ret.length() > 1) {
            ret.erase(ret.begin());
        }
        return ret;
    }
};
