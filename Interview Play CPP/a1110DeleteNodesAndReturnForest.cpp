//
//  a1110DeleteNodesAndReturnForest.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/26/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> to_del(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        dfs(nullptr, root, true,  to_del, res);
        return res;
        
    }
    
    void dfs(TreeNode* par, TreeNode* root, bool isLeft, set<int>& to_del, vector<TreeNode*>& res) {
        if (root == nullptr) return;
        
        bool deleteThis = false;
        if (to_del.find(root->val) != to_del.end()) {
            deleteThis = true;
        }
        
        if (par == nullptr && !deleteThis) res.push_back(root);
        
        dfs(deleteThis?nullptr:root, root->left, true,  to_del, res);
        dfs(deleteThis?nullptr:root, root->right, false, to_del, res);
        
        if (deleteThis) {
            root->left = nullptr;
            root->right = nullptr;
            if (par != nullptr) {
                if (isLeft) par->left = nullptr;
                else par->right = nullptr;
            }
        }
    }
};
