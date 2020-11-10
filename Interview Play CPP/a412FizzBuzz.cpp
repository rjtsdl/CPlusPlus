//
//  a412FizzBuzz.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/10/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for (int i =1; i<= n; i++) {
            if (i%15 ==0) ret.push_back("FizzBuzz");
            else if (i%3==0) ret.push_back("Fizz");
            else if (i%5==0) ret.push_back("Buzz");
            else ret.push_back(to_string(i));
        }
        return ret;
    }
};
