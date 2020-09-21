//
//  a604DesignCompressedStringIterator.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class StringIterator {
public:
    
    string res;
    int ptr = 0, num = 0;
    char ch = ' ';
    StringIterator(string compressedString) {
        res = compressedString;
    }
    
    char next() {
        if (!hasNext())
            return ' ';
        if (num == 0) {
            ch = res[ptr++];
            while (ptr < res.length() && res[ptr] >= '0' && res[ptr] <= '9' ) {
                num = num * 10 + res[ptr++] - '0';
            }
        }
        num--;
        return ch;
    }
    
    bool hasNext() {
        return ptr != res.length() || num != 0;
        
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
