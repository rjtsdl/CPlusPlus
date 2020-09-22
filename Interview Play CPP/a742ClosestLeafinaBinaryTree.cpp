//
//  a742ClosestLeafinaBinaryTree.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>

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
    void traverse(TreeNode* root, unordered_map<int, int>& parent, vector<int>& leaves)
    {
        if (!root) return;
        if (!root->left && !root->right) {
            leaves.push_back(root->val);
        }
        if (root->left) {
            parent[root->left->val] = root->val;
            traverse(root->left, parent, leaves);
        }
        if (root->right) {
            parent[root->right->val] = root->val;
            traverse(root->right, parent, leaves);
        }
    }
    
    int get_distance(int i, int k, unordered_map<int, int>& parent) {
        int temp_k = i;
        int temp_i = k;
        int distance = 0;
        while (temp_i != temp_k) {
            temp_i = (temp_i != parent[temp_i]) ? parent[temp_i] : k;
            temp_k = (temp_k != parent[temp_k]) ? parent[temp_k] : i;
        }
        
        temp_k = k;
        int lca = temp_i;
        while (temp_k != lca) {
            distance++;
            temp_k = parent[temp_k];
        }
        
        temp_i = i;
        while (temp_i != lca) {
            distance++;
            temp_i = parent[temp_i];
        }
        return distance;
    }
    
    int findClosestLeaf(TreeNode* root, int k) {
        vector<int> leaves;
        unordered_map<int, int> parent;
        if (!root) return -1;
        parent[root->val] = root->val;
        traverse(root, parent, leaves);
        
        int min_node = root->val;
        int min_distance = -1;
        for (unsigned i=0; i < leaves.size(); ++i) {

            int distance = get_distance(k, leaves[i], parent);
            if (distance < min_distance || min_distance < 0) {
                min_distance = distance;
                min_node = leaves[i];
            }
        }
        return min_node;
    }
};
