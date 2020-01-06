//
//  a971FlipBinaryTreeToMatchPreorderTraversal.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/5/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int>ans  ;
    int cur = -1 ;
    bool dfs(TreeNode* root,TreeNode* parent,int which, vector<int>& voyage)
    {
        ++cur ;
        bool lans = true ;
        if(root->val != voyage[cur])
        {
            //right child so not possible
            if(which == 1)return false ;
        
            //root element doesn't match
            if(parent == NULL) return false ;
            
            if(parent->left && parent->right) {
                //swap can only be performed if they are equal
                if(parent->right->val != voyage[cur])
                    return false ;
                    
                //perform  swap
                swap(parent->left, parent->right);
                ans.push_back(parent->val) ;
                
                //update the pointer to correct node
                root = parent->left  ;
            } else {
                return false;
            }
                
        }
        
        if(root->left) lans &= dfs(root->left , root , 0,voyage) ;
        if(root->right) lans &= dfs(root->right , root , 1,voyage) ;
            
        
       return lans ;
    }
    
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        ans.clear() ;
        cur = -1 ;
        
        if(root == NULL)return ans ;
        
        if(dfs(root,NULL,0,voyage))
            return ans ;
        else
        {
             ans.clear();
            ans.push_back(-1) ;
            return ans ;
        }
    }
};
