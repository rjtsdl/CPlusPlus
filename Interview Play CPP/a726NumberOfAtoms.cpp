//
//  a726NumberOfAtoms.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <stack>
#include <map>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Solution {
public:
    int i;
    map<string, int> parse(string formula) {
        int N = formula.size();
        map<string, int> count;
        while (i < N && formula[i] != ')') {
            if (formula[i] == '(') {
                i++;
                for (auto entry: parse(formula)) {
                    count[entry.first] += entry.second;
                }
            } else {
                int iStart = i++;
                while (i < N && formula[i] >= 'a' && formula[i] <= 'z') i++;
                string name = formula.substr(iStart, i-iStart);
                iStart = i;
                while (i < N && formula[i] >= '0' && formula[i] <= '9') i++;
                int multiplicity = iStart < i ? atoi(formula.substr(iStart, i-iStart).c_str()) : 1;
                count[name] += multiplicity;
            }
        }
        int iStart = ++i;
        while (i < N && formula[i] >= '0' && formula[i] <= '9') i++;
        if (iStart < i) {
            int multiplicity = atoi(formula.substr(iStart, i-iStart).c_str());
            for (auto key: count) {
                count[key.first] *= multiplicity;
            }
        }
        return count;
    }
    string countOfAtoms(string formula) {
        stringstream ans;
        i = 0;
        map<string, int> count = parse(formula);
        for (auto name: count) {
            ans << name.first;
            int multiplicity = name.second;
            if (multiplicity > 1) {
                ans << multiplicity;
            }
        }
        return ans.str();
    }
};
