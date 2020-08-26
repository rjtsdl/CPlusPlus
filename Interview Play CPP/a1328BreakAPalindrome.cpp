//
//  a1328BreakAPalindrome.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/26/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n <= 1) return "";
        int i = 0, j = n-1;
        while(i < j){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
            i++,j--;
        }
        palindrome[n-1] = 'b';
        return palindrome;
    }
};
