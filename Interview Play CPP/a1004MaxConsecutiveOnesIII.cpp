//
//  a1004MaxConsecutiveOnesIII.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
      int left = 0, right;
      for (right = 0; right < A.size(); right++) {
        // If we included a zero in the window we reduce the value of K.
        // Since K is the maximum zeros allowed in a window.
        if (A[right] == 0) K--;
        // A negative K denotes we have consumed all allowed flips and window has
        // more than allowed zeros, thus increment left pointer by 1 to keep the window size same.
        if (K < 0) {
          // If the left element to be thrown out is zero we increase K.
          if (A[left] == 0) K++;
          left++;
        }
      }
      return right - left;
    }
};
