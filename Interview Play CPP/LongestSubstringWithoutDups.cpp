//
//  LongestSubstringWithoutDups.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 10/18/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

class LongestSubstringWithoutDups
{
public:
    int lengthOfLongestSubstring(string s) {
        string longestSubstring = "";
        unordered_map<char, int> charMap;
        int leftPos = 0;
        int rightPos = 0;
        
        while (leftPos <= rightPos && rightPos < s.length()) {
            // right advance until going to get dup
            while (rightPos < s.length() && charMap.find(s[rightPos]) == charMap.end()) {
                charMap[s[rightPos]] = 1;
                rightPos++;
            }
            // keep a record
            if (rightPos - leftPos > longestSubstring.size()) {
                longestSubstring.assign(s.c_str() + leftPos, rightPos - leftPos);
            }
            
            // advance one step if possible
            if (rightPos < s.length()) {
                auto iter = charMap.find(s[rightPos]);
                if (iter != charMap.end()) {
                    iter->second++;
                    rightPos++;
                }
            }
            
            // get back to a safe phase
            while (leftPos <= rightPos && charMap[s[leftPos]] == 1) {
                charMap.erase(s[leftPos]);
                leftPos++;
            }
            if (charMap[s[leftPos]] == 2) {
                charMap[s[leftPos]]--;
                leftPos++;
            }
        }
        return (int)longestSubstring.size();
    }

};

/*
int main()
{
    string s = "aab";
    LongestSubstringWithoutDups obj;
    obj.lengthOfLongestSubstring(s);
    return 0;
    
}
 */
