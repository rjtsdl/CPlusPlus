//
//  GroupAnagrams.cpp
//  Interview Play CPP
//
//  Created by Jingtao on 2/8/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, int> theMap;
        
        for (string& str : strs) {
            string key = getTheKey(str);
            auto iter = theMap.find(key);
            if (iter == theMap.end()) {
                //No such one yet;
                theMap[key] = (int)ret.size();
                ret.push_back(vector<string>{str});
            }
            else
            {
                int index = iter->second;
                ret[index].push_back(str);
            }
        }
        
        for (auto& vec : ret) {
            sort(vec.begin(), vec.end());
        }
        return ret;
    }
    
    string getTheKey(const string str)
    {
        string ret = str;
        sort(ret.begin(), ret.end());
        return ret;
    }
};
/*
int main()
{
    Solution sol;
    vector<string> in = {""};
    sol.groupAnagrams(in);
}
*/