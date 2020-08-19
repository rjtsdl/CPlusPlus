//
//  a301RemoveInvalidParentheses.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        
        vector<string> res;
        int toRemoveCount = INT_MAX;
        unordered_set<string> visited;
        dfs(s, 0, res, 0, toRemoveCount, visited);
        return res;
        
    }
    
private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c: s) {
            count += (c == '(') - (c==')');
            if (count < 0) {
                return false;
            }
        }
        return count == 0;
    }
    
    bool isValidPrefix(const string& s) {
        int count = 0;
        for (char c: s) {
            count += (c == '(') - (c==')');
            if (count < 0) {
                return false;
            }
        }
        return count >= 0;
    }
    
    void dfs(string s, int start, vector<string>& res, int removedCount, int& toRemoveCount, unordered_set<string>& visited) {
        // cout << "entering " << s << " start " << start << "toRemoveCount" << toRemoveCount << endl;
        if (removedCount > toRemoveCount) {
            return;
        }
        if (isValid(s)) {
            
            if (visited.find(s) != visited.end()) {
                return;
            }
            
            if (removedCount == toRemoveCount) {
                // cout << "push: " << s << endl;
                visited.insert(s);
                res.push_back(s);
            } else if (removedCount < toRemoveCount) {
                toRemoveCount = removedCount;
                res.clear();
                // cout << "push: " << s << endl;
                visited.insert(s);
                res.push_back(s);
            }
        } else {
            if (start >= s.size() || !isValidPrefix(s.substr(0, start))) {
                return;
            }
            dfs(s, start+1, res, removedCount, toRemoveCount, visited);
            if (s[start] == '(' || s[start] == ')') {
                dfs (s.erase(start, 1), start, res, removedCount+1, toRemoveCount, visited);
            }
        }
    }
};
/*
int main() {
    Solution* sol = new Solution();
    string s = ")(";
    vector<string> o = sol->removeInvalidParentheses(s);
    for (string ss: o) {
        cout << ss << endl;
    }
}
 */
