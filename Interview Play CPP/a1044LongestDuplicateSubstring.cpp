//
//  a1044LongestDuplicateSubstring.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    
    /*
    Rabin-Karp with polynomial rolling hash.
        Search a substring of given length
        that occurs at least 2 times.
        Return start position if the substring exits and -1 otherwise.
        */
    int search(int L, int a, long modulus, int n, string S) {
      // compute the hash of string S[:L]
      long h = 0;
      for(int i = 0; i < L; ++i) h = (h * a + S[i]-'a') % modulus;

      // already seen hashes of strings of length L
      unordered_set<long> seen;
      seen.insert(h);
      // const value to be used often : a**L % modulus
      long aL = 1;
      for (int i = 1; i <= L; ++i) aL = (aL * a) % modulus;

      for(int start = 1; start < n - L + 1; ++start) {
        // compute rolling hash in O(1) time
        h = (h * a - (S[start - 1]-'a') * aL % modulus + modulus) % modulus;
        h = (h + S[start + L - 1]-'a') % modulus;
        if (seen.count(h)) return start;
          seen.insert(h);
      }
      return -1;
    }
    string longestDupSubstring(string S) {
        int n = S.length();
        // base value for the rolling hash function
        int a = 26;
        // modulus value for the rolling hash function to avoid overflow
        long modulus = (long)pow(2, 32);

        // binary search, L = repeating string length
        int left = 1, right = n;
        int L;
        while (left <= right) {
          L = left + (right - left) / 2;
          if (search(L, a, modulus, n, S) != -1) left = L + 1;
          else right = L - 1;
        }

        int start = search(left - 1, a, modulus, n, S);
        return S.substr(start, left - 1);
    }
    
    
};
