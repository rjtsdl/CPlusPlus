//
//  a708InsertintoaSortedCircularLinkedList.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>


class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            Node* ret =new Node(insertVal);
            ret->next = ret;
            return ret;
        }
        Node* prev = head;
        Node* cur = head->next;
        while (cur != head) {
            if ((prev->val < cur->val && insertVal <= cur->val && insertVal >= prev->val) || (prev->val > cur->val && (insertVal <= cur->val || insertVal >= prev->val))) {
                Node* newNd = new Node(insertVal);
                prev->next = newNd;
                newNd->next = cur;
                return head;
            }
            prev = cur;
            cur = cur->next;
        }
        
        Node* newNd = new Node(insertVal);
        prev->next = newNd;
        newNd->next = cur;
        return head;
    }
};
