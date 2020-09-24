//
//  a1180CountSubstringswithOnlyOneDistinctLetter.cpp
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
  int countLetters(string S) {
    int res = 0, pre = 0;
    char pc = '#';
    for (char &c : S) {
      pre = c == pc ? pre + 1 : 1;
      res += pre;
      pc = c;
    }
    return res;
  }
};
