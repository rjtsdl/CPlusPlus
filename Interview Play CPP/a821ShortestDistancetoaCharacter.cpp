//
//  a821ShortestDistancetoaCharacter.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        
        vector<int> ret(S.size(), INT_MAX/2);
        
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == C) {
                ret[i] = 0;
            } else {
                if (i>0) ret[i] = min(ret[i], ret[i-1] +1);
            }
        }
        
        for (int i = S.size()-1; i >= 0; i--) {
            if (S[i] == C) {
                ret[i] = 0;
            } else {
                if (i< S.size()-1) ret[i] = min(ret[i], ret[i+1] +1);
            }
        }
        
        return ret;
        
    }
};
