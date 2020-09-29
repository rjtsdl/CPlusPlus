//
//  a1265PrintImmutableLinkedListinReverse.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printReverse(ImmutableListNode* head, ImmutableListNode* tail) noexcept {
        if (head->getNext() == tail) {
            head->printValue();
            return;
        }
        ImmutableListNode* fast = head;
        ImmutableListNode* slow = head;
        while (fast != tail && fast->getNext() != tail) {
            fast = fast->getNext()->getNext();
            slow = slow->getNext();
        }
        printReverse(slow, tail);
        printReverse(head, slow);
    }

    void printLinkedListInReverse(ImmutableListNode* head) {
        if (head != nullptr) {
            printReverse(head, nullptr);
        }
    }
};
