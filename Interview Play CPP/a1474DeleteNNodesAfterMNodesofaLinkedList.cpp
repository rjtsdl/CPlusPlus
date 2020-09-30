//
//  a1474DeleteNNodesAfterMNodesofaLinkedList.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>


class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode pre_node(0);
        ListNode* node = &pre_node;
        node->next = head;

        while (node && node->next) {
            for (int i = 0; i < m; ++i)
                if (node)
                    node = node->next;
                else
                    break;

            for (int i = 0; i < n; ++i)
                if (node && node->next)
                    node->next = node->next->next;
                else
                    break;
        }

        return head;
    }
};
