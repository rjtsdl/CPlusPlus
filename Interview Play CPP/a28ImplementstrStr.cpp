//
//  a28ImplementstrStr.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/13/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        return kmp(haystack, needle);
        
    }
    
    int kmp(string haystack, string needle) {
        // build kmp_table for needle
        vector<int> kmp_table(needle.size(), 0);
        int i =1;
        int j =0;
        while (i < needle.size()) {
            if (needle[i] == needle[j]) {
                j++;
                kmp_table[i++] = j;
            } else if (j == 0) {
                kmp_table[i++] = 0;
            } else {
                j = kmp_table[j-1];
            }
        }
        
        // Using kmp table to get first index of substring
        i = 0;
        j = 0;
        
        while (j < needle.size() && i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else if (j == 0) {
                i++;
            } else {
                j = kmp_table[j-1];
            }
        }
        
        if (j >= needle.size()){
            return i-(int)needle.size();
        }
        
        return -1;
    }
    
    
};
