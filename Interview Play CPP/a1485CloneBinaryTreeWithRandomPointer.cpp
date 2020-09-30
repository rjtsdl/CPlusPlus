//
//  a1485CloneBinaryTreeWithRandomPointer.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    unordered_map<Node*,NodeCopy*> m;
    NodeCopy* get(Node * root){
        if(!root)
            return NULL;
        NodeCopy* re = new NodeCopy(root->val);
        re->left=copyRandomBinaryTree(root->left);
        re->right=copyRandomBinaryTree(root->right);
        m[root]=re;
        return re;
    }
    void set(NodeCopy* & re,Node * root){
        if(!root)
            return;
        re->random=m[root->random];
        set(re->left,root->left);
        set(re->right,root->right);
    }
    
    NodeCopy* copyRandomBinaryTree(Node* root) {
        m[NULL]=NULL;
        auto re=get(root);
        set(re,root);
        
        return re;
    }
};
