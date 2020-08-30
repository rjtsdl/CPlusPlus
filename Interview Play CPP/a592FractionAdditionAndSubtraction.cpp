//
//  a592FractionAdditionAndSubtraction.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Solution {
public:
    
    int mcm(int a, int b) {
        a = abs(a), b = abs(b);
        int l = lcm(a,b);
        return a/l*b;
    }
    
    int lcm(int a, int b) {
        a = abs(a), b = abs(b);
        if (a < b) return lcm(b,a);
        if (b == 0) return a;
        return  lcm(b, a%b);
    }
    string fractionAddition(string expression) {
        int norminator = 0;
        int denorminator = 1;
        
        int curNor = 0;
        int curDen = 1;
        bool norDone = false;
        
        int i = 0;
        int sign = 1;
        
        while (i < expression.size()) {
            if (expression[i] == '-') {
                sign = -1;
                i++;
            } else if (expression[i] == '+') {
                sign = 1;
                i++;
                
            }else if (!norDone && expression[i] >= '0' && expression[i] <= '9') {
                int k = i++;
                
                while (i < expression.size() && expression[i] != '/' ) {
                    i++;
                }
                curNor = atoi(expression.substr(k, i-k).c_str());
            } else if (expression[i] == '/') {
                i++;
                norDone = true;
            } else if (norDone && expression[i] >= '0' && expression[i] <= '9') {
                int k = i++;
                
                while (i < expression.size() && expression[i] >= '0' && expression[i] <= '9') {
                    i++;
                }
                curDen = atoi(expression.substr(k, i-k).c_str());
                norDone = false;
                
                int mc = mcm(denorminator, curDen);
                norminator *= mc/denorminator;
                denorminator = mc;
                curNor *= mc/curDen;
                norminator += sign * curNor;
                
                curNor = 0;
                curDen = 1;
                sign = 1;
                
                int l = lcm(norminator, denorminator);
                
                norminator /= l;
                denorminator /= l;
            }
            
        }
        
        stringstream ss;
        ss << norminator << "/" << denorminator;
        
        return ss.str();
        
        
    }
};
