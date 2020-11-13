//
//  AddTwoNumbers.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 10/18/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class AddTwoNumbers
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ret = nullptr;
        ListNode* cur = nullptr;
        int car = 0;
        while (l1 != nullptr || l2 != nullptr || car !=0) {
            int sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += car;
            
            if (sum >= 10) {
                car = 1;
                sum = sum%10;
            }
            else{
                car = 0;
            }
            
            if (ret == nullptr) {
                ret = new ListNode(sum);
                cur = ret;
            }
            else{
            
                cur->next = new ListNode(sum);
                cur = cur->next;
            }
        }
        
        if (ret == nullptr) {
            ret = new ListNode(0);
        }
        return ret;
    }
};
