//
//  a938RangeSumOfBST.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include "math.h"

using namespace std;

class Solution {
public:
    struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == nullptr || L > R) return 0;
        
        int total = root->val >= L && root->val <= R ? root->val: 0;
        total += rangeSumBST(root->left, L, min(root->val, R));
        total += rangeSumBST(root->right, max(L, root->val), R);
        return total;
    }
};
