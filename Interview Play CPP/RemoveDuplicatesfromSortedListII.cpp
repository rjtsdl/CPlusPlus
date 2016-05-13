//
//  RemoveDuplicatesfromSortedListII.cpp
//  Interview Play CPP
//
//  Created by Jingtao on 5/12/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

/**
 * Definition for singly-linked list.*/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        
        
        ListNode* cur = preHead;
        bool isDup = false;
        int dupVal = 0;
        
        while (cur->next != nullptr) {
            if (!isDup && cur->next->next != nullptr && cur->next->val == cur->next->next->val) {
                dupVal = cur->next->val;
                isDup = true;
            }
            
            if (!isDup) {
                cur = cur->next;
            }
            else{
                while (cur->next != nullptr && cur->next->val == dupVal) {
                    cur->next = cur->next->next;
                }
                isDup = false;
            }
        }
        return preHead->next;
    }
};