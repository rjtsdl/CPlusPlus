//
//  a872LeafSimilarTrees.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> tree1;
        stack<TreeNode*> tree2;
        
        pushLeft(root1, tree1);
        pushLeft(root2, tree2);
        
        TreeNode* leaf1 = nextLeaf(tree1);
        TreeNode* leaf2 = nextLeaf(tree2);
        
        while (leaf1 != nullptr && leaf2 != nullptr && leaf1->val == leaf2->val) {
            leaf1 = nextLeaf(tree1);;
            leaf2 = nextLeaf(tree2);
        }
        
        if (leaf1 == leaf2) return true;
        return false;
    }
    
    TreeNode* nextLeaf(stack<TreeNode*>& st) {
        while (!st.empty()) {
            TreeNode* t = st.top();st.pop();
            if (t->left == t->right) {
                return t;
            }
            
            pushLeft(t->right, st);
        }
        return nullptr;
    }
    
    void pushLeft(TreeNode* root, stack<TreeNode*>& st) {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }
};
