//
//  a828CountUniqueCharsOfAllSubstrOfAGivenString.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/26/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniqueLetterString(string S) {
        
        map<char, vector<int>> index;
        vector<int> peek(26, 0);
        int N = S.size();

        for (int i = 0; i < S.size(); ++i) {
            char c = S[i];
            if (index.find(c) == index.end()) index[c] = vector<int>();
            index[c].push_back(i);
        }
        
        long ans = 0;
        for (auto& p : index) {
            for (int i =0; i < p.second.size(); ++i) {
                ans += (p.second[i]- (i>0 ? p.second[i-1]: -1)) * ((i< p.second.size()-1 ? p.second[i+1] : S.size()) - p.second[i]);
            }
        }
        
        return (int) ans % (int)(1e9+7);

    }
    /*
    long get(char c, map<char, vector<int>>& index, vector<int>& peek) {
        auto indexes = index[c];
        int i = peek[c - 'A'];
        return indexes[i+1] - indexes[i];
    }
     */
};

int main() {
    string S = "ABA";
    Solution* sol = new Solution();
    int count = sol->uniqueLetterString(S);
    cout << "count: " << count << endl;
    return 0;
}
