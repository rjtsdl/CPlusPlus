//
//  a819MostCommonWord.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/15/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        std::for_each(paragraph.begin(), paragraph.end(), [](char &c) {
            c = ::tolower(c);
            if (c < 'a' || c > 'z' ) {
                c = ' ';
            }
        });
        unordered_set<string> banSet;
        banSet.insert(banned.begin(), banned.end());
        
        unordered_map<string, int> counter;
        
        int prv = 0;
        int found = paragraph.find(' ', prv);
        while (found != string::npos) {
            string s =  paragraph.substr(prv, found-prv);
            cout << "s: " << s << endl;
            if (s.size() > 0) {
                if (banSet.count(s) == 0) {
                    counter[s]++;
                }
            }
            prv = found+1;
            found = paragraph.find(' ', prv);
        }
        
        if (prv < paragraph.size()) {
            string s = paragraph.substr(prv);
            if (s.size() > 0) {
                if (banSet.count(s) == 0) {
                    counter[s]++;
                }
            }
        }
        
        int maxCount = 0;
        string maxWord = "";
        
        for (auto kv : counter) {
            if (kv.second > maxCount) {
                maxCount = kv.second;
                maxWord = kv.first;
            }
        }
        
        return maxWord;
        
        
    }
};
/*

int main() {
    Solution* sol = new Solution();
    vector<string> banned{"hit"};
    cout << "most common word: " << sol->mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", banned);
}
*/
