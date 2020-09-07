//
//  a1239MaximumLengthofaConcatenatedStringwithUniqueCharacters.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/6/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxLen = 0;
    int target_string[26];
    
    void backtrack(vector<string>& arr, int ind) {
        if(ind == arr.size()) {
            maxLen = max(maxLen, size());
            return;
        }
        insert(arr[ind]);
        if(isValid(arr[ind])) backtrack(arr, ind+1);
        remove(arr[ind]);
        backtrack(arr, ind+1);
    }
    
    int maxLength(vector<string>& arr) {
        memset(target_string, 0, sizeof target_string);
        backtrack(arr, 0);
        return maxLen;
    }
    
/*
    Helper functions
*/
private:
    bool isValid(string& str) {
        for(char c : str) if(target_string[c-'a'] > 1) return false;
        return true;
    }
    
    void insert(string& str) {
        for(char c : str) target_string[c-'a']++;
    }
    
    void remove(string& str) {
        for(char c : str) target_string[c-'a']--;
    }
    
    int size() {
        int sz = 0;
        for(auto count : target_string) if(count > 0) sz++;
        return sz;
    }
};
