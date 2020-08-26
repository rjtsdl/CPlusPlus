//
//  a1375BulbSwitcherIII.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/26/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int>& A)
    {
      int count = 0, maxM = INT_MIN;
      for (int i = 0; i < A.size(); i++)
      {
        maxM = max(maxM, A[i]);
        
        if (maxM == i + 1) count++;
      }

      return count;
    }
};
