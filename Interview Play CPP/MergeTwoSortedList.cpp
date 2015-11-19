//
//  MergeTwoSortedList.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/18/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(0);
        ListNode* cur = preHead;
        
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        
        if (l1 != nullptr) {
            cur->next = l1;
        }
        else
        {
            cur->next = l2;
        }
        
        return preHead->next;
        
    }
};