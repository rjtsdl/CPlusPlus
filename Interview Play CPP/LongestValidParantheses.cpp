//
//  LongestValidParantheses.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/27/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        
        // forward iteration
        int longestLength = 0;
        int longestLengthSofar =0;
        int countSofar = 0;
        for (int i =0; i < s.length(); ++i) {
            if (s[i] == '(') {
                countSofar++;
                longestLengthSofar++;
            }
            else if (s[i] == ')')
            {
                countSofar--;
                longestLengthSofar++;
            }
            
            if (countSofar < 0) {
                countSofar = 0;
                longestLengthSofar = 0;
            }
            else if (countSofar == 0)
            {
                //could be a valid length
                if (longestLengthSofar > longestLength) {
                    longestLength = longestLengthSofar;
                }
            }
        }
        
        longestLengthSofar =0;
        countSofar = 0;
        for (int i =(int)s.length()-1; i >=0; --i) {
            if (s[i] == ')') {
                countSofar++;
                longestLengthSofar++;
            }
            else if (s[i] == '(')
            {
                countSofar--;
                longestLengthSofar++;
            }
            
            if (countSofar < 0) {
                countSofar = 0;
                longestLengthSofar = 0;
            }
            else if (countSofar == 0)
            {
                //could be a valid length
                if (longestLengthSofar > longestLength) {
                    longestLength = longestLengthSofar;
                }
            }
        }
        
        return longestLength;
        
    }
};