//
//  a987VerticalOrderTraversalOfABinaryTree.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/1/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>

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
    // hd is horizontal distance  and  ht is distance from top
    void getmyans(TreeNode* root,map<int,map<int,vector<int>>>&mp,int hd,int ht)
    {
        if(root==nullptr)
            return ;
        
        mp[hd][ht].push_back(root->val);
        
        getmyans(root->left,mp,hd-1,ht+1);
        getmyans(root->right,mp,hd+1,ht+1);
        
        return;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,vector<int>>>mp;
        vector<vector<int>> ans;
        
        getmyans(root,mp,0,0);
        
        
        for(auto x:mp)
        {
            vector<int>temp;
            for(auto y:x.second)
            {
                sort(y.second.begin(),y.second.end()); // this  sorting for if any have same level as well as horizontal distance
                for(auto w:y.second)
                {
                    temp.push_back(w);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};
