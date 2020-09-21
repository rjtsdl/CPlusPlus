//
//  a536ConstructBinaryTreefromString.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/20/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

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
    TreeNode* str2tree(string s) {
        int index = 0;
        return str2treenode(s, index);
        
    }
    
    TreeNode* str2treenode(const string& s, int& index) {
        if (index >= s.size() || s[index] == ')') {
            return nullptr;
        }
        
        int sign = 1;
        int number = 0;
        
        while (index < s.size() && s[index] != '(' && s[index] != ')') {
            if (s[index] == '-') {
                sign = -1;
            } else if (s[index] >= '0' && s[index] <= '9') {
                number = number * 10 + (int)(s[index]-'0');
            }
            index++;
        }
        
        TreeNode* root = new TreeNode(sign * number);
        
        if (index < s.size() && s[index] == '(') {
            index++;
            root->left = str2treenode(s, index);
            index++;
        }
        
        if (index < s.size() && s[index] == '(') {
            index++;
            root->right = str2treenode(s, index);
            index++;
        }
        
        return root;
    }
};
