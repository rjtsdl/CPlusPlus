//
//  a622DesignCircularQueue.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/27/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class MyCircularQueue {
    
public:
    vector<int> m_elems;
    int m_head;
    int m_tail;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        m_elems = vector<int>(k+1, 0);
        m_head = 0;
        m_tail = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        m_elems[m_tail] = value;
        m_tail = (m_tail+1) % m_elems.size();
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        m_head = (m_head+1)%m_elems.size();
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) return -1;
        return m_elems[m_head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        return m_elems[(m_tail+m_elems.size()-1)%m_elems.size()];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return m_head == m_tail;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (m_tail+1)%m_elems.size() == m_head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
