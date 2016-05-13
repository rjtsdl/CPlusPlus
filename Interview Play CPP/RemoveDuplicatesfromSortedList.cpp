//
//  RemoveDuplicatesfromSortedList.cpp
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
        
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode* cur = head;
        
        while (cur->next!= nullptr) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
};