//
//  a1249MinimumRemoveToMakeValidParentheses.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/13/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack <int> pStack; // to maintain indexes of '(' for which we need a matching ')'
        vector<int> pList; // Indexes with invalid '(' or ')' -> to be removed
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                pStack.push(i); // remember index of '(' in stack
            } else if (s[i] == ')') {
                if (pStack.empty()) {
                    // invalid paranthesis, should be removed -> add it to the list
                    pList.push_back(i);
                } else {
                    pStack.pop(); // found a ')' -> pop the most recent '(' as they form a pair
                }
            }
            // char is an alphabet, proceed to next char
        }
        
        while (!pStack.empty()) {
            // all the remaining '(' on stack are invalid
            // add the indexes to the List
            int index = pStack.top();
            pStack.pop();
            pList.push_back(index);
        }
        
        // sort the list of indexes in descending order
        // To remove the character from tail end of the string
        // so the indexes of paranthesis remain same as the string gets updated
        // Alternatively we could have used a ordered set and traverse it in reverse order to remove chars from input string
        std::sort(pList.begin(), pList.end(), greater<int>());
        for (int index : pList) {
            s.erase(s.begin()+index);
        }
        
        return s;
    }
};

/*
int main() {
    
    Solution* sol = new Solution();
    cout << sol->minRemoveToMakeValid("lee(t(c)o)de)") << endl;
    
}
*/
