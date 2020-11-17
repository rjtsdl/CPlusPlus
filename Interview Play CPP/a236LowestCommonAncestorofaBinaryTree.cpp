//
//  a236LowestCommonAncestorofaBinaryTree.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // second value definition
        // 0 means not checked at all
        // 1 means checked itself
        // 2 means checked itself and left
        // 3 menas checked itself and left and right
        stack<pair<TreeNode*, int>, vector<pair<TreeNode*, int>>> _runS;
        int num_found;
        int probableD;
        
        _runS.push(make_pair(root, 0));
        num_found = 0;
        probableD = 0;
        while (!_runS.empty()) {
            auto& tp = _runS.top();
            if (tp.second == 0) {
                tp.second++;
                if (tp.first == p) {
                    num_found++;
                    if (num_found == 1) {
                        probableD = _runS.size();
                    }
                }
                if (tp.first == q) {
                    num_found++;
                    if (num_found == 1) {
                        probableD = _runS.size();
                    }
                }
                if (num_found == 2) {
                    while (_runS.size() > probableD) {
                        _runS.pop();
                    }
                    return _runS.top().first;
                }
            } else if (tp.second == 1) {
                tp.second++;
                if (tp.first->left != nullptr) _runS.push(make_pair(tp.first->left, 0));
                
            } else if (tp.second == 2) {
                tp.second++;
                if (tp.first->right != nullptr) _runS.push(make_pair(tp.first->right, 0));
                
            } else {
                _runS.pop();
                if (_runS.size() < probableD) {
                    probableD = _runS.size();
                }
            }
        }
        
        return nullptr;
    }
};
