//
//  a1258SynonymousSentences.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/6/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        
        vector<set<string>> groupOfSyn;
        groupOfSyn.push_back({});
        unordered_map<string, int> wordToGrp;
        int i = 1;
        
        for (vector<string>& p : synonyms) {
            set<string> temp;
            int grp = 0;
            if (wordToGrp[p[0]] || wordToGrp[p[1]]) {
                grp = max(wordToGrp[p[0]], wordToGrp[p[1]]);
                wordToGrp[p[0]] = grp;
                wordToGrp[p[1]] = grp;
                groupOfSyn[grp].insert({p[0], p[1]});
            } else {
                wordToGrp[p[0]] = i;
                wordToGrp[p[1]] = i;
                groupOfSyn.push_back({p[0], p[1]});
                i++;
            }
        }
        
        vector<string> tokens;
        string tmp;
        for(auto ch : text) {
            if(ch == ' '){
                tokens.push_back(tmp);
                tmp.clear();
            } else {
                tmp += ch;
            }
        }
        
        if (tmp != "") {
            tokens.push_back(tmp);
        }
        
        vector<string> ret;
        ret.push_back("");
        
        for (auto w : tokens) {
            if (wordToGrp[w]) {
                int grp = wordToGrp[w];
                vector<string> temp;
                for (string& r: ret) {
                    for (string s : groupOfSyn[grp]) {
                        temp.push_back(r + (r != "" ? " ":"") + s);
                    }
                }
                ret = temp;
            } else {
                for (string& r : ret) {
                    if (r != "") {
                        r += " ";
                    }
                    r += w;
                }
            }
        }
        return ret;
    }
};
