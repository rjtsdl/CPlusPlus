//
//  SwapNodeInPairs.cpp
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
public:
    
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
    ListNode* swapPairs(ListNode* head) {
        ListNode* preHead = new ListNode(0);
        ListNode* cur = preHead;
        cur->next = head;
        
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* theNext = cur->next;
            ListNode* theNextNext = theNext->next;
            
            theNext->next = theNextNext->next;
            cur->next = theNextNext;
            theNextNext->next = theNext;
            cur = theNext;
            
        }
        return preHead->next;
        
    }
};