//
//  RemoveDuplicatesfromSortedListII.cpp
//  Interview Play CPP
//
//  Created by Jingtao on 5/12/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <utility>
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
//    ListNode* deleteDuplicates(ListNode* head) {
//
//        ListNode* preHead = new ListNode(0);
//        preHead->next = head;
//
//
//        ListNode* cur = preHead;
//        bool isDup = false;
//        int dupVal = 0;
//
//        while (cur->next != nullptr) {
//            if (!isDup && cur->next->next != nullptr && cur->next->val == cur->next->next->val) {
//                dupVal = cur->next->val;
//                isDup = true;
//            }
//
//            if (!isDup) {
//                cur = cur->next;
//            }
//            else{
//                while (cur->next != nullptr && cur->next->val == dupVal) {
//                    cur->next = cur->next->next;
//                }
//                isDup = false;
//            }
//        }
//        return preHead->next;
//    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        unique_ptr<ListNode> preHead (new ListNode(0));
        ListNode* pre = preHead.get();
        ListNode* cur = head;
        bool isDup = false;
        
        while (cur != nullptr) {
            if (!isDup && (cur->next == nullptr || cur->next->val != cur->val)) {
                pre->next = cur;
                cur = cur->next;
                pre->next->next = nullptr;
                pre = pre->next;
                continue;
            } else if (isDup && (cur->next == nullptr || cur->next->val != cur->val)) {
                isDup = false;
                cur = cur->next;
                continue;
            } else {
                isDup = true;
                cur = cur->next;
            }
        }
        
        return preHead->next;      
    }
};
