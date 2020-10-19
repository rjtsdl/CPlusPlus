//
//  a889ConstructBinaryTreefromPreorderandPostorderTraversal.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        vector<TreeNode*> r = construct(pre, post, 0, pre.size()-1, 0, post.size()-1);
        return r[0];
    }
    
    vector<TreeNode*> construct(vector<int>& pre, vector<int>& post,
                        int preI, int preJ, int postI, int postJ) {
        if (preJ-preI != postJ-postI) return {nullptr, nullptr};
        if (preJ<preI) return {nullptr, nullptr};
        
        
        
        if (pre[preI] == post[postJ]) {
            TreeNode* ret = new TreeNode(pre[preI]);
            preI++;
            postJ--;
            vector<TreeNode*> lr = construct(pre, post, preI, preJ, postI, postJ);
            ret->left = lr[0];
            ret->right = lr[1];
            return {ret, nullptr};
        }
    
        int len = 0;
        while (post[postI+len] != pre[preI]) {
            len++;
        }
        
        vector<TreeNode*> l = construct(pre, post, preI, preI+len, postI, postI+len);
        vector<TreeNode*> r = construct(pre, post, preI+len+1, preJ, postI+len+1, postJ);
        
        return {l[0], r[0]};
        
    }
};
