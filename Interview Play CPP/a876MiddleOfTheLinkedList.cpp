//
//  a876MiddleOfTheLinkedList.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/25/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>


class Solution {
public:
    /**
    * Definition for singly-linked list. */
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode* middleNode(ListNode* head) {
        ListNode* step2 = head;
        ListNode* step1 = head;
        
        while (step2!= nullptr) {
            step2 = step2->next;
            if (step2 == nullptr) break;
            
            step2 = step2->next;
            step1 = step1->next;
        }
        return step1;
    }
};
