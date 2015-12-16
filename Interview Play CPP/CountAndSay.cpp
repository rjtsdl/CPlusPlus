//
//  CountAndSay.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 12/15/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    // Count and say
    string countAndSay(string in) {
        char theOne = '0' + 10;
        int count = 0;
        string res = "";
        for (char c : in) {
            if (c != theOne && count > 0) {
                res.push_back('0' + count);
                res.push_back(theOne);
                theOne = c;
                count = 1;
            }
            else if (c == theOne)
            {
                count++;
            }
            else if (c >= '0' + 10 || count == 0)
            {
                // very initial stage
                theOne = c;
                count = 1;
            }
        }
        if (count > 0) {
            res.push_back('0' + count);
            res.push_back(theOne);
        }
        return res;
    }
    
    // n is the sequence number
    string countAndSay(int n) {
        string res = "1";
        for (int i = 2; i <= n; i++) {
            res = countAndSay(res);
        }
        return res;
    }
};