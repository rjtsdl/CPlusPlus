//
//  a863AllNodesDistanceKInBinaryTree.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/


class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        stack<TreeNode*> rootToTarget;
        dfs(root, target, rootToTarget);
        
        cout << "stack top: " << rootToTarget.top()->val << endl;
        
        if (rootToTarget.empty() || rootToTarget.top() != target) {
            return {};
        }
        
        vector<int> res = rootDistanceK(target, K);
        TreeNode* prev = target; rootToTarget.pop();
        int step = 1;
        while (!rootToTarget.empty()) {
            cout << "stack top: " << rootToTarget.top()->val << endl;
            if (step == K) {
                res.push_back(rootToTarget.top()->val);
            } else {
                if (rootToTarget.top()->left != prev) {
                    vector<int> l = rootDistanceK(rootToTarget.top()->left, K-step-1);
                    res.insert(res.end(), l.begin(), l.end());
                }
                
                if (rootToTarget.top()->right != prev) {
                    vector<int> r = rootDistanceK(rootToTarget.top()->right, K-step-1);
                    res.insert(res.end(), r.begin(), r.end());
                }
            }
            prev = rootToTarget.top(); rootToTarget.pop(); step++;
        }
        
        return res;
        
        
    }
    
    void dfs(TreeNode* cur, TreeNode* target, stack<TreeNode*>& rootToTarget) {
        if (!rootToTarget.empty() && rootToTarget.top() == target) return;
        if (cur != nullptr) {
            rootToTarget.push(cur);
            if (rootToTarget.top() != target) {
                dfs(cur->left, target, rootToTarget);
            }
            
            if (rootToTarget.top() != target) {
                dfs(cur->right, target, rootToTarget);
            }
            
            if (rootToTarget.top() != target) {
                rootToTarget.pop();
            }
        }
    }
    
    vector<int> rootDistanceK(TreeNode* root, int K) {
        if (root == nullptr || K < 0) {
            return {};
        }
        if (K == 0) {
            return {root->val};
        }
        
        vector<int> left = rootDistanceK(root->left, K-1);
        vector<int> right = rootDistanceK(root->right, K-1);
        
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};
