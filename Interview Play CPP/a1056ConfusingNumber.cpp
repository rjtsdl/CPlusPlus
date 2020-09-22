//
//  a1056ConfusingNumber.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/22/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    bool confusingNumber(int N) {
        //set match pair 0,0, 9,6, 6,9
        //each time taks one from end by % as reminder
        //make new number by + reminder's pair 9 to 6, 6 to 9
        unordered_map<int, int> map;
        map[0] = 0;
        map[1] = 1;
        map[6] = 9;
        map[9] = 6;
        map[8] = 8;
        
        int x = N;
        
        int newNum = 0;
        
        while (x != 0) {
            int reminder = x % 10;
            if (map.find(reminder) == map.end())
                return false;
            
            int next = map[reminder];
            newNum = newNum * 10 + next;
            
            x = x/10;
        }
        
        return newNum != N;
    }
};
