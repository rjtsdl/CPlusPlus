//
//  a979DistributeCoinsInBinaryTree.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/27/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <iostream>

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
    int distributeCoins(TreeNode* root) {
        int total = 0;
        needDFS(root, total);
        return total;
    }
    
    
    int needDFS(TreeNode* root, int& total) {
        if (root == nullptr) return 0;
        if (root->left == nullptr & root->right == nullptr) return root->val-1;
        int leftNeed = needDFS(root->left, total);
        int rightNeed = needDFS(root->right, total);
        total += abs(leftNeed) + abs(rightNeed);
        return root->val-1 + leftNeed + rightNeed;
    }
};
