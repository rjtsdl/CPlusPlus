//
//  a1134ArmstrongNumber.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/23/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;


class Solution {
public:
  bool isArmstrong(int n)
  {
    string s = to_string(n);
    for (char c : s)
      n -= (int)pow(c-'0', s.size());
    
    return n == 0;
  }
};
