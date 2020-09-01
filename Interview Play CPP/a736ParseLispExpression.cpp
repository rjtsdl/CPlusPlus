//
//  a736ParseLispExpression.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/1/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <list>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<unordered_map<string, int>> scope;

    int evaluate(string expression) {
        scope.push_back(unordered_map<string, int>());
        int ans = evaluate_inner(expression);
        scope.pop_back();
        return ans;
    }

    int evaluate_inner(string expression) {
        if (expression[0] != '(') {
            if (expression[0] >= '0' && expression[0] <= '9' || expression[0] == '-')
                return atoi(expression.c_str());
            for (int i = scope.size() - 1; i >= 0; --i) {
                if (scope[i].count(expression))
                    return scope[i][expression];
            }
        }
        
        int start = expression[1] == 'm' ? 6:5;
        vector<string> tokens = parse(expression.substr(start, expression.size()-1-start));
        if (expression.substr(1, 3) == "add") {
            return evaluate(tokens[0]) + evaluate(tokens[1]);
        } else if (expression.substr(1, 4) == "mult") {
            return evaluate(tokens[0]) * evaluate(tokens[1]);
        } else {
            for (int j = 1; j < tokens.size(); j += 2) {
                scope.back()[tokens[j-1]] = evaluate(tokens[j]);
            }
            return evaluate(tokens.back());
        }
    }

    vector<string> parse(string expression) {
        vector<string> ans;
        int bal = 0;
        
        string buf;
        auto pos = expression.find_first_not_of(" ", 0);
        while (pos != string::npos) {
            auto next = expression.find_first_of(" ", pos);
            string token = expression.substr(pos, next-pos);
            
            for (char c : token) {
                if (c == '(') bal++;
                if (c == ')') bal--;
            }
            if (buf.size() > 0) buf += " ";
            buf += token;
            
            if (bal == 0) {
                ans.push_back(buf);
                buf = "";
            }
            
            pos = expression.find_first_not_of(" ", next);
            
        }
        if (buf.size() > 0) {
            ans.push_back(buf);
        }
        return ans;
    }
};
