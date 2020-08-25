//
//  a402RemoveKDigits.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/24/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <list>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        list<char> st;
            
        for(char digit : num) {
            while(!st.empty() && k > 0 && st.back() > digit) {
                st.pop_back();
                k -= 1;
            }
            st.push_back(digit);
        }
            
        /* remove the remaining digits from the tail. */
        for(int i=0; i<k; ++i) {
            st.pop_back();
        }
            
        // build the final string, while removing the leading zeros.
        string ret = "";
        bool leadingZero = true;
        for(char digit: st) {
          if(leadingZero && digit == '0') continue;
          leadingZero = false;
          ret += digit;
        }
            
        /* return the final string  */
        if (ret.size() == 0) return "0";
        return ret;
    }
};
