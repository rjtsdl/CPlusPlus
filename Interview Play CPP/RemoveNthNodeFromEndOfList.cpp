//
//  RemoveNthNodeFromEndOfList.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/17/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>



class Solution {
    
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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (n < 1) {
            return head;
        }
        
        int count = n;
        ListNode* forward = head;
        
        while (count > 1 && forward != nullptr) {
            forward = forward->next;
            --count;
        }
        if (count > 1) {
            // we reach to the end, no nth from the end
            return head;
        }
        
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        
        while (forward->next != nullptr) {
            forward = forward->next;
            preHead = preHead->next;
        }
        
        if (preHead->next == head) {
            head = head->next;
        }
        preHead->next = preHead->next->next;
        return head;
        
    }
};