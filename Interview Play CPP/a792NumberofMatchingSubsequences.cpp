//
//  a792NumberofMatchingSubsequences.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<char, vector<string> > firstLetterM;
        
        for (string w : words) {
            firstLetterM[w[0]].push_back(w);
        }
        
        int count = 0;
        
        for (char c : S) {
            vector<string> tmp;
            for(string s : firstLetterM[c]) {
                if(s.size() == 1) {
                    count++;
                } else {
                    s = s.substr(1);
                    if (s[0] == c) {
                        tmp.push_back(s);
                    } else {
                        firstLetterM[s[0]].push_back(s);
                    }
                }
            }
            firstLetterM[c] = tmp;
            
            
        }
        
        return count;
    }
};

/*
int main() {
    string S = "dsahjpjauf";
    vector<string> words = {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};
    Solution sol;
    cout << "num matching sub seq: " << sol.numMatchingSubseq(S, words) << endl;
}
 */
