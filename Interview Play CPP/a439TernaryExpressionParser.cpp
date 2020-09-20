//
//  a439TernaryExpressionParser.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/19/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string eval(string& s)
    {
        string ans="";
        if(s[0]=='T')
        {
            ans+=s[2];
        }
        else
        {
            ans+=s[4];
        }
        return ans;

    }
    string parseTernary(string expression) {
        stack<string> st;
        string cur="";
        for(int i=0;i<expression.size();i++)
        {
            if(i<expression.size()-1 && ((expression[i]=='T')||(expression[i]=='F')) && expression[i+1]=='?')
            {
                st.push(cur);
                cur="";
                cur+=expression[i];
                cur+='?';

                i++;

            }
            else
            {
                cur+=expression[i];
            }

            while(cur.size()==5)
            {
                string temp=eval(cur);
                string left="";
                if(!st.empty())
                {
                    left=st.top();
                    st.pop();
                }
                cur=left+temp;
            }
        }
        return cur;

    }
};
