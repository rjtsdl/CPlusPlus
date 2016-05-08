//
//  RotateList.cpp
//  Interview Play CPP
//
//  Created by Jingtao on 5/8/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int listLen = 0;
        ListNode* prev = nullptr;
        ListNode* pos = head;
        while (pos != nullptr) {
            ++listLen;
            prev = pos;
            pos = pos->next;
        }
        if (listLen == 0 || listLen == 1) {
            return head;
        }
        
        k = k % listLen;
        if (k == 0) {
            return head;
        }
        ListNode* newHead = head;
        ListNode* newPrev = nullptr;
        for (int i = 0; i < (listLen - k); ++i) {
            newPrev = newHead;
            newHead = newHead->next;
        }
        
        prev->next = head;
        newPrev->next = nullptr;
        return newHead;
        
    }
};