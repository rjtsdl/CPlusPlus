//
//  a1138AlphabetBoardPath.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/8/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>


class Solution {
public:
    string alphabetBoardPath(string t) {
        pair<int, int> pos[26] = {{0,0}, {0,1}, {0,2}, {0,3}, {0,4},
                                  {1,0}, {1,1}, {1,2}, {1,3}, {1,4},
                                  {2,0}, {2,1}, {2,2}, {2,3}, {2,4},
                                  {3,0}, {3,1}, {3,2}, {3,3}, {3,4},
                                  {4,0}, {4,1}, {4,2}, {4,3}, {4,4},
                                  {5,0}
                                 };
        
        string ans{};
        
        for (int i = 0; i < t.length(); i++) {
            int dy = pos[t[i] - 'a'].first - (i > 0 ? pos[t[i-1] - 'a'].first : 0);
            int dx = pos[t[i] - 'a'].second - (i > 0 ? pos[t[i-1] - 'a'].second : 0);
            
            
            if (dy > 0 and dx < 0) {
                ans.append(abs(dx), 'L');
                ans.append(abs(dy), 'D');
            } else if (dy < 0 and dx > 0) {
                ans.append(abs(dy), 'U');
                ans.append(abs(dx), 'R');
            } else {
                if (dy > 0)
                    ans.append(abs(dy), 'D');
                else
                    ans.append(abs(dy), 'U');

                if (dx > 0)
                    ans.append(abs(dx), 'R');
                else
                    ans.append(abs(dx), 'L');
            }
            
            
            ans.append("!");
        }
        
        return ans;
    }
};
