//
//  a408ValidWordAbbreviation.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        // abbreviations may contain a digit that matches
        // a number of characters (any character) in the "word."
        // Idea will be to proceed through the abbr and the
        // word, consuming characters as we go in both. If
        // we reach the end of one or the other, but there's
        // remaining items in the other argument, return "false",
        // otherwise return "true".
        
        int i = 0, j = 0;   // indices into 'word' and 'abbr'
        
        while (i < word.length() && j < abbr.length()) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0') // this makes no sense, but won't pass the test otherwise
                    return false;

                int digit = 0;
                while (j < abbr.length() && isdigit(abbr[j])) {
                    digit *= 10;
                    digit += abbr[j] - '0';
                    j++;
                }

                // if (j == abbr.length())
                //     return false;

                i += digit;
            } else {
                if (word[i] != abbr[j])
                    return false;
                i++;
                j++;
            }
        }
        
        // if we consumed all chars in both args, return
        // "true".
        return i == word.length() && j == abbr.length();
    }
};
