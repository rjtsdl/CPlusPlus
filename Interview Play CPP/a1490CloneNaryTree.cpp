//
//  a1490CloneNaryTree.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> copyMap;
    Node* cloneTree(Node* root) {
        if (root == nullptr) return nullptr;
        if (copyMap.count(root)) return copyMap[root];
        
        vector<Node*> copyVec;
        
        for (Node* c : root->children) {
            copyVec.push_back(cloneTree(c));
        }
        
        Node* newRoot = new Node(root->val);
        newRoot->children = copyVec;
        return newRoot;
    }
};
