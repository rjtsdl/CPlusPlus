//
//  a1261FindElementsinaContaminatedBinaryTree.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/5/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>


// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements {
public:
    FindElements(TreeNode* root) {
        m_root = root;
        recover(m_root, 0);
    }
    
    bool find(int target) {
        return findNode(target) != nullptr;
        
    }

private:
    TreeNode* m_root;
    
    void recover(TreeNode* root, int val) {
        if (root == nullptr) return;
        
        root->val = val;
        recover(root->left, 2*val +1);
        recover(root->right, 2*val +2);
    }
    
    TreeNode* findNode(int target) {
        if (target == 0) return m_root;
        int parentVal = (target - 1)/2;
        TreeNode* parNode = findNode(parentVal);
        if (parNode == nullptr) return nullptr;
        if (target == 2*parentVal+1) {
            return parNode->left;
        } else if (target == 2*parentVal+2) {
            return parNode->right;
        } else {
            return nullptr;
        }
    }
};
