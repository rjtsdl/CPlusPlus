//
//  a1100FindKLengthSubstringsWithNoRepeatedCharacters.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/23/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int result=0, count=0, right=0, n=S.size();
        unordered_map<char, int> ht;
        if(K>n) return 0;
        
        
        while(right<n){
            if(right>=K){
                ht[S[right-K]]--;
                if(ht[S[right-K]]==0){
                    ht.erase(S[right-K]);
                    count--;
                }
            }

            if(ht.find(S[right])==ht.end())
                count++;
            
            ht[S[right]]++;
            right++;
        
            if(count==K)
                result++;
        }
        
        return result;
    }
};
