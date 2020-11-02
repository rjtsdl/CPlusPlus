//
//  a559MaximumDepthofNaryTree.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/2/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

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
    int maxDepth(Node* root) {
        if (root == nullptr) {
          return 0;
        } else if (root->children.empty()) {
          return 1;
        } else {
            int md = 0;
            for (auto it : root->children) {
                md = max(md, maxDepth(it));
            }
            return md+1;
        }
    }
};
