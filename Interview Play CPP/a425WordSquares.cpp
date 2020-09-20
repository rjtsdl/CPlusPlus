//
//  a425WordSquares.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/19/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string,vector<string>> prefixMap;
    vector<vector<string>> wordSquares(vector<string>& words) {
        storePrefixWords(words);
        vector<vector<string>> result;
        
        for(auto word: words){
            vector<string> ls;
            ls.push_back(word);
            backTrack(1,ls,result);
        }
        return result;
    }
    
    void backTrack(int level, vector<string> &ls, vector<vector<string>> &result){
        if(level==ls[0].size()){
            result.push_back(ls);
            return;
        }
        string prefix = "";
        for(auto word: ls){
            prefix = prefix + word[level];
        }
        
        vector<string> pfxwords;
        pfxwords = prefixMap[prefix];
        for(auto word: pfxwords){
            ls.push_back(word);
            backTrack(level+1,ls,result);
            ls.pop_back();
        }
    }
    void storePrefixWords(vector<string> words){
        for(auto word:words){
            for(int i=1;i<=word.size();i++){
                string prefix = word.substr(0,i);
                prefixMap[prefix].push_back(word);
            }
        }
    }
};
