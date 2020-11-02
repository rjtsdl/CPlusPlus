//
//  a558LogicalORofTwoBinaryGridsRepresentedasQuadTrees.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/2/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (!quadTree1 && !quadTree2) return NULL;
        if (!quadTree2) return quadTree1;
        if (!quadTree1) return quadTree2;
        
        if (quadTree1->isLeaf && quadTree1->val) return quadTree1;
        if (quadTree2->isLeaf && quadTree2->val) return quadTree2;
        if (quadTree1->isLeaf && !quadTree1->val) return quadTree2;
        if (quadTree1->isLeaf && !quadTree1->val) return quadTree1;
        
        auto tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        auto tr = intersect(quadTree1->topRight, quadTree2->topRight);
        auto bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        auto br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        
        if(tl->val == tr->val && tl->val == bl->val && tl->val == br->val &&
                    tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf) {
            return new Node(tr->val, true, NULL, NULL, NULL, NULL);
        } else {
            return new Node(false, false, tl, tr, bl, br);
        }
    }
};
