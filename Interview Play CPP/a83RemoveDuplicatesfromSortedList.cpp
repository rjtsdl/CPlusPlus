//
//  RemoveDuplicatesfromSortedList.cpp
//  Interview Play CPP
//
//  Created by Jingtao on 5/12/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <functional>

using namespace std;

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
        ListNode* cur = head;
        
        while (cur != nullptr) {
            if (cur->next != nullptr && cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
