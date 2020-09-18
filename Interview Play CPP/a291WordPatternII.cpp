//
//  a291WordPatternII.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // remaining count of each char in pattern
        vector<int> count;
        // mappings from letter to string we have chosen.
        unordered_map<char, string> dict;
        // strings from str that we used.
        unordered_set<string> used;
        // last index in pattern, after which all characters have already been seen before.
        int last_index = 0;
        bool wordPatternMatch(string pattern, string str) {
            if(str.size() < pattern.size())
                return false;
            
            count.resize(26, 0);
            
            for(int i = 0; i < pattern.size(); i++){
                if(++count[pattern[i] - 'a'] == 1)
                    last_index = i;
            }
            
            return helper(pattern, 0, str, 0);
        }
        
        bool helper(string& p, int i, string& s, int j){
           // each letter in p should map to non empty string.
           // Pigeonhole principle
            if(p.size() - i > s.size() - j)
                return false;
            
            // if you reached the end of either one, then other one should have reached end as well for positive result.
            if(i == p.size() || j == s.size())
                return i == p.size() && j == s.size();
            
            // we have mapped all the chars.
            // at this point you have mapped all unique chars in pattern
            // You need to make sure that the total number of chars that we will get from the mapping
            // will equal to the remaining number of chars in s.
            if(i == last_index + 1){
                int chars_needed = 0;
                for(int f = 0; f < 26; f++){
                    char let = 'a' + f;
                    if(dict.count(let))
                        chars_needed += (count[f] * dict[let].size());
                }
                if(chars_needed != s.size() - j)
                    return false;
            }
            
            // we have already mapped this letter to something
            if(dict.count(p[i])){
                string& expected = dict[p[i]];
                int size = expected.size();
                // check the size and check if the mapping matches to what is in s.
                if(j + size > s.size() || s.substr(j, size) != expected){
                    return false;
                }
                else{
                    // it does match, so apply the mapping and check recursively on the rest.
                    count[p[i] - 'a']--;
                    bool res = helper(p, i + 1, s, j + size);
                    count[p[i] - 'a']++;
                    return res;
                }
            }
            
            // try different versions.
            string mapping = "";
            for(int t = j; t < s.size(); t++){
                // accumulate
                mapping += s[t];
                
                // if this substring from s has already been used by some other char, then skip
                // as we can't have a situation where     'x'->"abc" and    f->"abc"
                if(used.insert(mapping).second == false)
                     continue;
                
                // try this mapping
                dict[p[i]] = mapping;
                count[p[i] - 'a']--;
                
                if(helper(p, i + 1, s, t + 1))
                    return true;
                
                // backtrack
                //  erase the mapping and return count in whatever state it was before
                used.erase(mapping);
                count[p[i] - 'a']++;
                dict.erase(p[i]);
            }
            // we have tried everything but didn't succeed.
            return false;
        }
};
