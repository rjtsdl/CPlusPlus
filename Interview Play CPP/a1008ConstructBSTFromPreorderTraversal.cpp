//
//  a1008ConstructBSTFromPreorderTraversal.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/26/20.
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return helper(preorder, idx, INT_MIN, INT_MAX);
        
    }
    
    TreeNode* helper(vector<int>& preorder, int& idx, int lb, int rb) {
        if (idx >= preorder.size()) return nullptr;
        if (preorder[idx] <= lb || preorder[idx] >= rb) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = helper(preorder, idx, lb, root->val);
        root->right = helper(preorder, idx, root->val, rb);
        return root;
    }
};
