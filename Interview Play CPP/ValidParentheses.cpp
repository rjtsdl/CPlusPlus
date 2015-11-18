//
//  ValidParentheses.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/18/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        
        stack<char> theStack;
        for(char c : s)
        {
            switch (c) {
                case '{':
                    theStack.push('{');
                    break;
                case '}':
                    if (theStack.empty() || theStack.top() != '{') {
                        return false;
                    }
                    theStack.pop();
                    break;
                case '[':
                    theStack.push('[');
                    break;
                case ']':
                    if (theStack.empty() || theStack.top() != '[') {
                        return false;
                    }
                    theStack.pop();
                    break;
                case '(':
                    theStack.push('(');
                    break;
                case ')':
                    if (theStack.empty() || theStack.top() != '(') {
                        return false;
                    }
                    theStack.pop();
                    break;
                default:
                    break;
            }
        }
        
        
        
        return theStack.empty();
        
    }
};