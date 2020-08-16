//
//  a735AsteroidCollision.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/15/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a)
    {
        stack<int>left,right;
        vector<int>ans;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i]>=0)
            {
                right.push(a[i]);
            }
            else if(a[i]<0)
            {
                if(!right.empty())
                {
                    int val=right.top();
                    if(val==abs(a[i]))
                    {
                        right.pop();
                    }
                    else if(val>abs(a[i]))
                    {
                        
                    }
                    else
                    {
                        int flag=0;
                        while(!right.empty() && right.top()<abs(a[i]))
                        {
                            right.pop();
                        }
                        if(!right.empty() && right.top()==abs(a[i]))
                        {
                            right.pop();
                            flag=1;
                        }
                        if(!right.empty() && right.top()>abs(a[i]))
                        {
                            flag=1;
                        }
                        if(flag==0)
                            ans.push_back(a[i]);
                    }
                }
                else
                {
                    ans.push_back(a[i]);
                }
            }
        }
        stack<int>tmp;
        while(!right.empty())
        {
            tmp.push(right.top());
                right.pop();
        }
        while(!tmp.empty())
        {
           ans.push_back(tmp.top());
               tmp.pop();
        }
        return ans;
    }
};
