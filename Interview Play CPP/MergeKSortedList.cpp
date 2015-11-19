//
//  MergeKSortedList.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/19/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto compare = [](ListNode* l1, ListNode* l2) -> bool { return l1->val > l2->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> heap(compare);
        
        for (const auto& listNode : lists) {
            if (listNode != nullptr) {
                heap.push(listNode);
            }
        }
        ListNode* preHead = new ListNode(0);
        ListNode* cur = preHead;
        
        while (!heap.empty()) {
            cur->next = heap.top();
            heap.pop();
            if (cur->next->next!= nullptr) {
                heap.push(cur->next->next);
            }
            
            cur = cur->next;
        }
        
        return  preHead->next;
    }
};
