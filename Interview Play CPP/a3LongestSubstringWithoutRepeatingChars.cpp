//
//  LongestSubstringWithoutDups.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 10/18/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

class LongestSubstringWithoutDups
{
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> nextJ;
        int i = 0;
        int j = 0;
        int maxL = 0;
        
        while (j < s.size()) {
            i = max(i, nextJ[s[j]]);
            maxL = max(maxL, (++j)-i);
            nextJ[s[j-1]] = j;
            
        }
        return maxL;
    }

};

/*
int main()
{
    string s = "aab";
    LongestSubstringWithoutDups obj;
    obj.lengthOfLongestSubstring(s);
    return 0;
    
}
 */
