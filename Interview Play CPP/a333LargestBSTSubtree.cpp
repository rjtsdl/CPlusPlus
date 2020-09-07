//
//  a333LargestBSTSubtree.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/7/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

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
    
    int maxSize;
    int largestBSTSubtree(TreeNode* root) {
        maxSize = 0;
        findBSTSubtree(root);
        return maxSize;
    }
    
    vector<int> findBSTSubtree(TreeNode* root) {
        if (root == nullptr) return {INT_MAX,INT_MIN,0};
        
        vector<int> l = findBSTSubtree(root->left);
        vector<int> r = findBSTSubtree(root->right);
        
        maxSize = max(max(maxSize, l[2]), r[2]);
        
        if (l[2] != -1 && r[2] != -1 && root->val < r[0] && root->val > l[1]) {
            maxSize = max(maxSize, 1+l[2]+r[2]);
            return {min(l[0], root->val), max(r[1], root->val), 1+l[2]+r[2]};
        }
        
        return {0, 0, -1};
    }
};
