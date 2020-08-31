//
//  a1026MaximumDiffBetweenNodeAndAcestor.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/31/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 *
 */
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
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
    
    pair<int,int> dfs(TreeNode* node, int& ans)
    {
        if(node==nullptr)
        {
            return {INT_MAX,INT_MIN};
        }
        
        auto l=dfs(node->left,ans);
        auto r=dfs(node->right,ans);
        
        int min_v=min(l.first,r.first);
        int max_v=max(l.second,r.second);
        
        if(min_v!=INT_MAX) ans=max(ans,abs(min_v-node->val));
        if(max_v!=INT_MIN) ans=max(ans,abs(max_v-node->val));
        
        return {min(min_v,node->val),max(max_v,node->val)};
    }
};
