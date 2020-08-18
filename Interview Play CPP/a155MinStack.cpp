//
//  a155MinStack.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <list>
#include "math.h"

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        stack.clear();
        minStack.clear();
        
    }
    
    list<int> stack;
    list<int> minStack;
    
    void push(int x) {
        stack.push_back(x);
        minStack.push_back(minStack.empty() ?x : std::min(minStack.back(),x));
    }
    
    void pop() {
        stack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
