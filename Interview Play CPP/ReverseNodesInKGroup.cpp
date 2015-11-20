//
//  ReverseNodesInKGroup.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/19/15.
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
class Solution {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k<=1) {
            return head;
        }
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* cur = preHead;
        
        
        while (true) {
            ListNode* fwd = cur;
            int count = k;
            
            do{
                fwd = fwd->next;
                --count;
            }
            while (count > 0 && fwd != nullptr);
        
            if (count > 0 || fwd == nullptr) {
                break;
            }
        
            // Reverse k nodes
            // Only k-1 times
            // keep prev and now
            count = k-1;
            ListNode* prev = cur->next;
            ListNode* now = prev->next;
            while (count > 0) {
                // Cut the fwd
                prev->next = prev->next->next;
                ListNode* hold = cur->next;
                cur->next = now;
                now = now->next;
                cur->next->next = hold;
                --count;
            }
            
            count = k;
            while (count > 0) {
                cur = cur->next;
                --count;
            }
        }
        return preHead->next;
    }
};