//
//  a524LongestWordinDictionarythroughDeleting.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // a better solution than this greedy approach
    // or better greedy
    /*
     https://techdevguide.withgoogle.com/paths/foundational/find-longest-word-in-dictionary-that-subsequence-of-given-string/#
    */
    bool isSubsequence(string a,string b){
        int smallpointer=0;
        for(int largepointer=0;largepointer<b.size() && smallpointer<a.size();largepointer++){
            if(a[smallpointer]==b[largepointer]){
                smallpointer++;
            }
        }
        
        return smallpointer==a.size();
    }
    
    
    string findLongestWord(string s, vector<string>& d) {
        
        string ans;
        
        sort(d.begin(),d.end(),[](string s1,string s2){
           return s1.size()!=s2.size() ? s1.size()>s2.size() : s1<s2;
        });
        
        for(auto str:d){
            if(isSubsequence(str,s)){
                return str;
            }
        }
        
        return "";
    }
};
