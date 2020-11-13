//
//  a895MaximumFrequencyStack.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/20/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <stack>

using namespace std;

class FreqStack {
    map<int, int> freq;
    map<int, stack<int>> group;
public:
    FreqStack() {
    }
    
    void push(int x) {
        freq[x]++;
        
        group[freq[x]].push(x);
    }
    
    int pop() {
        if (group.empty()) return -1;
        
        int k = (*group.rbegin()).first;
        int x = group[k].top();group[k].pop();
        if (group[k].empty()) {
            group.erase(k);
        }
        freq[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
