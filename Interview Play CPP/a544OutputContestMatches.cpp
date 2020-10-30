//
//  a544OutputContestMatches.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/27/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string findContestMatch(int n) {
        vector<string> teams(n);
        for (int i = 0; i < n; i++) {
            teams[i] = to_string(i+1);
        }
        
        for (; n > 1; n = n/2) {
            for (int i =0; i< n/2; i++) {
                teams[i] = "(" + teams[i] + "," + teams[n-i-1] + ")";
            }
        }
        
        return teams[0];
    }
};
