//
//  LengthOfLastWord.cpp
//  Interview Play CPP
//
//  Created by Jingtao on 5/7/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    /*
    int lengthOfLastWord(string s) {
        char delimiter = ' ';
        
        while (s.back() == delimiter) {
            s.pop_back();
        }
        
        size_t lastIndex = s.find_last_of(delimiter);
        
        if (lastIndex == string::npos) {
            return (int)s.length();
        }
        else
        {
            return (int)(s.length() - lastIndex - 1);
        }
        return 0;
    }
    */
    // Without using find_last_of
    
    int lengthOfLastWord(string s) {
        char delimiter = ' ';
        
        while (s.back() == delimiter) {
            s.pop_back();
        }
        
        int count = 0;
        while (!s.empty() && s.back() != delimiter) {
            ++count;
            s.pop_back();
        }
        return count;
    }
    
};