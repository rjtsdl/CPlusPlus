//
//  a105ConstructBinaryTreefromPreorderandInorderTraversal.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

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
    int index =0;
    TreeNode* binaryTree(vector<int>& pre,vector<int>& in,int s,int e){
        if(s > e){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[index]);
        index++;
        if(s == e){
            return root;
        }
        int newIndex= 0;
        for(int i=s;i<=e;i++){
            if(in[i] == root->val){
                newIndex = i;
                break;
            }
        }
        root->left = binaryTree(pre,in,s,newIndex-1);
        root->right = binaryTree(pre,in,newIndex+1,e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = binaryTree(preorder,inorder,0,preorder.size()-1);
        return root;
    }
};
