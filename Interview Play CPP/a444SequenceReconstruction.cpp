//
//  a444SequenceReconstruction.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/7/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        vector<int> ridx(org.size()+1, 0);
        vector<bool> visited(org.size()+1, false);
        int visitedCount = 0;
        
        for (int i =0; i < org.size(); i++ ) {
            ridx[org[i]] = i;
        }
        
        for (vector<int>& s : seqs) {
            int prevIndex = -1;
            
            for (int n: s) {
                if (n > org.size()) {
                    return false;
                }
                
                if (prevIndex + 1 == ridx[n] && !visited[n]) {
                    visited[n] = true;
                    visitedCount++;
                } else if (prevIndex >= ridx[n]) {
                    return false;
                }
                
                prevIndex = ridx[n];
            }
        }
        
        return visitedCount == org.size();
    }
};
