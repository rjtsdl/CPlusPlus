//
//  ImplStrStr.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/21/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> KMPProcessing(string needle)
    {
        vector<int> match(needle.length(), -1);
        int j = -1;
        for (int i = 1; i < needle.length(); i++) {
            while (j>=0 && needle[j+1] != needle[i]) {
                j = match[j];
            }
            
            if (needle[j+1] == needle[i]) {
                j++;
            }
            match[i] = j;
        }
        
        return std::forward<vector<int>>(match);
    }
    
    int strStr(string haystack, string needle) {
        //Need to handle "" case
        if (needle.length() <= 0) {
            return 0;
        }
        if (haystack.length() <= 0) {
            return -1;
        }
        vector<int> match = KMPProcessing(needle);
        int j = -1;
        for (int i =0 ; i < haystack.length(); i++) {
            while (j>=0 && needle[j+1] != haystack[i]) {
                j = match[j];
            }
            if (haystack[i] == needle[j+1]) {
                j++;
            }
            
            if (j == needle.length() - 1) {
                return i- (int)needle.length() + 1;
            }
        }
        return -1;
        
    }
};
/*
int main()
{
    Solution sol;
    return sol.strStr("mississippi", "issip");
}
 */


