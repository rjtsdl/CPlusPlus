//
//  a430FlattenAMultilevelDoublyLinkedList.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/22/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    class Node {
    public:
        int val;
        Node* prev;
        Node* next;
        Node* child;
    };
    
    Node* flatten(Node* head) {
        
        Node* prev = nullptr;
        dfs(prev, head);
        return head;
        
    }
    
    void dfs(Node* &prev, Node* cur) {
        if (prev != nullptr) prev->next = cur;
        if (cur == nullptr) return;
        cur->prev = prev;
        
        prev = cur;
        Node* ln = cur->next;
        if (cur->child != nullptr) {
            cur->next = cur->child;
            cur->child = nullptr;
            dfs(prev, cur->next);
        }
        dfs(prev, ln);
    }
};
