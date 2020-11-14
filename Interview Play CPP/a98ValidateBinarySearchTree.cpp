//
//  a98ValidateBinarySearchTree.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <stack>
#include <climits>

using namespace std;


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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        stack<TreeNode*> st;
        
        pushLeft(root, st);
        int cur = st.top()->val;
        TreeNode* rt = st.top()->right;
        st.pop();
        pushLeft(rt, st);
        
        
        while (!st.empty()) {
            if (st.top()->val <= cur) return false;
            cur = st.top()->val;
            
            rt = st.top()->right;
            st.pop();
            pushLeft(rt, st);
        }
        
        return true;
        
    }
    
    void pushLeft(TreeNode* node, stack<TreeNode*>& st) {
        while (node  != nullptr) {
            st.push(node); node = node->left;
        }
    }
};
