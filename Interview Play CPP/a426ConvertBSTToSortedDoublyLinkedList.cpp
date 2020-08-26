//
//  a426ConvertBSTToSortedDoublyLinkedList.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/25/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;



class Solution {
public:

    class Node {
    public:
        int val;
        Node* left;
        Node* right;

        Node() {}

        Node(int _val) {
            val = _val;
            left = NULL;
            right = NULL;
        }

        Node(int _val, Node* _left, Node* _right) {
            val = _val;
            left = _left;
            right = _right;
        }
    };
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;
        
        auto p = flat(root);
        p[0]->left = p[1];
        p[1]->right = p[0];
        return p[0];
    }
    
    vector<Node*> flat(Node* root) {
        if (root == nullptr) return {nullptr, nullptr};
        
        Node* left = nullptr;
        Node* right = nullptr;
        auto lp = flat(root->left);
        if (lp[0] == nullptr || lp[1] == nullptr) {
            left = root;
        } else {
            lp[1]->right = root;
            root->left = lp[1];
            left = lp[0];
        }
        
        auto rp = flat (root->right);
        if (rp[0] == nullptr || rp[1] == nullptr) {
            right = root;
        } else {
            rp[0]->left = root;
            root->right = rp[0];
            right = rp[1];
        }
        
        return {left, right};
    }
};
