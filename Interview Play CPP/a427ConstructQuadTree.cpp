//
//  a427ConstructQuadTree.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
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
    Node* construct(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        return constructSub(grid, {0,0}, {m, n});
        
    }
    
    Node* constructSub(vector<vector<int>>& grid, vector<int> topLeft, vector<int> bottomRight) {
        if (topLeft[0] >= bottomRight[0] || topLeft[1] >= bottomRight[1]) {
            return nullptr;
        }
        
        if (topLeft[0] + 1 == bottomRight[0] && topLeft[1] + 1 == bottomRight[1]) {
            return new Node(grid[topLeft[0]][topLeft[1]], true);
        }
        
        Node* tl = constructSub(grid, {topLeft[0], topLeft[1]}, {topLeft[0] + (bottomRight[0] - topLeft[0]+1)/2, topLeft[1] + (bottomRight[1] - topLeft[1]+1)/2});
        Node* tr = constructSub(grid, {topLeft[0], topLeft[1] + (bottomRight[1] - topLeft[1]+1)/2}, {topLeft[0] + (bottomRight[0] - topLeft[0]+1)/2, bottomRight[1]});
        Node* bl = constructSub(grid, {topLeft[0] + (bottomRight[0] - topLeft[0]+1)/2, topLeft[1]}, {bottomRight[0], topLeft[1] + (bottomRight[1] - topLeft[1]+1)/2});
        Node* br = constructSub(grid, {topLeft[0] + (bottomRight[0] - topLeft[0]+1)/2, topLeft[1] + (bottomRight[1] - topLeft[1]+1)/2}, {bottomRight[0], bottomRight[1]});
        
        if (isLeafTrue(tl) && isLeafTrue(tr) && isLeafTrue(bl) && isLeafTrue(br)) {
            return new Node(true, true);
        }
        
        if (isLeafFalse(tl) && isLeafFalse(tr) && isLeafFalse(bl) && isLeafFalse(br)) {
            return new Node(false, true);
        }
        
        return new Node(true, false, tl, tr, bl, br);
        
    }
    
    bool isLeafTrue(Node* n) {
        return n == nullptr || (n->isLeaf && n->val);
    }
    
    bool isLeafFalse(Node* n) {
        return n == nullptr || (n->isLeaf && !n->val);
    }
};
