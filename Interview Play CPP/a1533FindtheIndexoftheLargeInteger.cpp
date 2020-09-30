//
//  a1533FindtheIndexoftheLargeInteger.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        return getIdx(reader, 0, reader.length() - 1);
    }
    
    int getIdx(ArrayReader &reader, int start, int end)
    {
        if (start == end)
            return end;

        const auto dist_side = (end - start) / 3;
        
        const auto end_left = start + dist_side;
        const auto start_right = end - dist_side;
/*

           |< MID >|
[?????????????????????????????] <<- array
 |        |         |        |
 |< LEFT >|         |< RIGHT>|
 |        |         |        |
 |     end_left     |        |
 |             start_right   |
start                       end

*/
            
        const auto cmp = reader.compareSub(start, end_left, start_right, end);
        if (cmp == 1)
            return getIdx(reader, start, end_left);
        if (cmp == -1)
            return getIdx(reader, start_right, end);
        
        return getIdx(reader, end_left + 1, start_right - 1);
    }
};
