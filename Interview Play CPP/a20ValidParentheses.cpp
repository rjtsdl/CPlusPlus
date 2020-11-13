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
    bool isValid(string str) {
        stack<char> s;
        for(int i=0;i<str.size();i++)
        {
            if(s.empty())s.push(str[i]);
            else if(str[i]=='}' && s.top()=='{')s.pop();
            else if(str[i]==']' && s.top()=='[')s.pop();
            else if(str[i]==')' && s.top()=='(')s.pop();
            else s.push(str[i]);
        }
        if(s.empty())return true;
        else return false;
    }
};
