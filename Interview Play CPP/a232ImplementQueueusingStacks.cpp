//
//  a232ImplementQueueusingStacks.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> _inS;
    stack<int> _outS;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        _inS.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret = peek();
        _outS.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if (_outS.empty()) {
            while (!_inS.empty()) {
                _outS.push(_inS.top()); _inS.pop();
            }
        }
        return _outS.top();
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return _outS.empty() && _inS.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
