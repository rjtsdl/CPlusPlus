//
//  a1522DiameterofNAryTree.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int diameter(Node* root) {
        maxDepth(root);
        return res;
    }
    
    int maxDepth(Node* root){
        if(!root) return 0;
        vector<int> vdepth;
        for(auto p:root->children) vdepth.push_back(maxDepth(p));
        sort(vdepth.begin(), vdepth.end(), greater<int>());
        if(vdepth.size() == 1){
            res = max(res, vdepth[0]);
        }
        else if(vdepth.size() >1){
            res = max(res, vdepth[0]+vdepth[1]);
        }
        return 1 + (vdepth.empty() ? 0 : vdepth[0]);
    }
    
    int res = 0;
};
