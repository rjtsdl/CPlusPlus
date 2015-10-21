//
//  LongestPalindromeSubstring.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 10/20/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class LongestPalindromeSubstring
{
public:
    string longestPalindrome(string s)
    {
        string longestSub = "";
        int totalLen = (int)s.length();
        bool pal[totalLen][totalLen+1];
        
        for (int start = totalLen -1; start >= 0; --start)
        {
            for (int len = 0; len <= totalLen - start; ++len)
            {
                if (len < 2 || (s[start] == s[start + len -1] && pal[start + 1][len - 2]))
                {
                    pal[start][len] = true;
                    if (len > longestSub.size())
                    {
                        longestSub.assign(s.c_str() + start, len);
                    }
                }
                else
                {
                    pal[start][len] = false;
                }
            }
        }
        
        return longestSub;
    }
};
