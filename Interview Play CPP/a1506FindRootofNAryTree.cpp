//
//  a1506FindRootofNAryTree.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    Node* findRoot(vector<Node*> tree)
    {
        int sum = 0, total = 0;

        for (auto node : tree)
        {
            total += node->val;

            for (auto child : node->children)
                sum += child->val;
        }

        for (auto node : tree)
            if (node->val == total - sum)
                return node;

        return nullptr;
    }
};


