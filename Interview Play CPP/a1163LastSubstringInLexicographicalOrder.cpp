//
//  a1163LastSubstringInLexicographicalOrder.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/19/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
        /*
        if (s.size() <= 1) {
            return "";
        }
        
        return helper(s);
         */
        int max = INT_MIN;
        int ans = s.size();
        
        for (int i=0;i<s.size();i++){
            if (i !=0 && s[i] == s[i-1]) continue;
            if (s[i] > max) {
                max = s[i];
                ans = i;
                continue;
            }
            
            if (s[i] == max && lexicographical_compare(s.begin()+i,s.end(),s.begin() + ans,s.end())==false) {
                ans = i;
            }
        }
        if (ans == s.size()) return "";
        return s.substr(ans) ;
    }
    
    string helper(string s) {
        list<int> startIndex;
        for (int i =0; i < s.size(); ++i) {
            if (i!= 0 && s[i] == s[i-1]) continue;
            startIndex.push_back(i);
        }
        int offSet = 0;
        
        
        list<int> maxCharStartIndex;
        while (startIndex.size() > 1) {
            char maxChar = 'a'-1;
            int n = startIndex.size();
            for (int i=0; i < n; ++i) {
                
                int ind = startIndex.front();
                startIndex.pop_front();
                if (ind+offSet >= s.size()) {
                    if (maxChar < 'a') {
                        maxCharStartIndex.push_back(ind);
                    }
                    continue;
                }
                char c = s[ind+offSet];
                if (s[ind+offSet] >= maxChar) {
                    if (s[ind+offSet] > maxChar) {
                        maxChar = c;
                        maxCharStartIndex.clear();
                    }
                    
                    if (maxCharStartIndex.size() == 0 || ind != maxCharStartIndex.back()+1) {
                        maxCharStartIndex.push_back(ind);
                        
                    }
                    
                }
                
            }
            if (maxCharStartIndex.size() > 0) {
                startIndex = maxCharStartIndex;
                maxCharStartIndex = list<int>();
                offSet++;
            }
        }
        
        return s.substr(startIndex.front());
    }
    
    
};
/*
int main() {
    Solution* sol = new Solution();
    cout << sol->lastSubstring("zrziy") << endl;
    return 0;
}
 */
