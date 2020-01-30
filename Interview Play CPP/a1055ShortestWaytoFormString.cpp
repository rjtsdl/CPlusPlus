//
//  a1055ShortestWaytoFormString.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    int shortestWay(string source, string target) {
        
        int idt = 0;
        int ids = 0;
        
        int count = 0;
        
        while (idt < target.size()) {
            int previdt = idt;
            while (ids < source.size() && idt < target.size()) {
                if (source[ids] == target[idt]) {
                    idt++;
                }
                ids++;
            }
            
            if (idt == previdt) {
                return -1;
            }
            count++;
            ids = 0;
        }
        
        return count;
    }
};
