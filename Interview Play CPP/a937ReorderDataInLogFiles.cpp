//
//  a937ReorderDataInLogFiles.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/11/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<string> dig;
        for (auto i = logs.begin(); i != logs.end(); ) {
            auto ifirst = i->find_first_of(' ');
            if (  (*i)[ifirst+1] >= '0' && (*i)[ifirst+1] <= '9' ) {
                dig.push_back(*i);
                i = logs.erase(i);
            } else {
                i++;
            }
        }
        
        
        auto comp = [](string const& a, string const& b)->bool {
            auto af = a.find_first_of(' ');
            auto bf = b.find_first_of(' ');
            
            if (a.substr(af+1) != b.substr(bf+1)) {
                return a.substr(af+1) < b.substr(bf+1);
            }
            
            return a.substr(0, af) < b.substr(0,bf);
            
        };
        
        sort(logs.begin(), logs.end(), comp);
        logs.insert(logs.end(), dig.begin(), dig.end());
        return logs;
        
    }
};
