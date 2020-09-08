//
//  a510InorderSuccessorinBSTII.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/7/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>


class Solution {
public:
    class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* parent;
    };
    Node* inorderSuccessor(Node* node) {
        if (node->right != nullptr) {
            Node* temp = node->right;
            while (temp->left != nullptr) temp = temp->left;
            return temp;
        }
        
        if (node->parent != nullptr) {
            Node* temp = node;
            Node* up = node->parent;
            
            while (up != nullptr && up->left != temp) {
                temp = up;
                up = up->parent;
            }
            
            return up;
        }
        
        return nullptr;
        
    }
};
