//
//  a314BinaryTreeVerticalOrderTraversal.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <map>

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
    map<int, vector<int>> _store;
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == nullptr) return {};
        // node, column
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            _store[q.front().second].push_back(q.front().first->val);
            if (q.front().first->left != nullptr) q.push(make_pair(q.front().first->left, q.front().second-1));
            if (q.front().first->right != nullptr) q.push(make_pair(q.front().first->right, q.front().second+1));
            q.pop();
            
        }
        
        vector<vector<int>> ret;
        for (auto kv : _store) {
            ret.push_back(kv.second);
        }
        return ret;
        
    }
};
