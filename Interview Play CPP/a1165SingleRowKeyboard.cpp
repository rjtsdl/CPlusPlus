//
//  a1165SingleRowKeyboard.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/24/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int count=0;
        int sum=0;
        int opos=0;
        int a;
        int position=0;
        for(int i=0;i<word.length();i++){
            position= keyboard.find(word[i]);
            a=abs(opos-position);
            count =count+a;
            opos=position;
            
        }
        
        
        
    return count;
    }
};
