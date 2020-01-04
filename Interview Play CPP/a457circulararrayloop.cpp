//
//  a457circulararrayloop.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/3/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <assert.h>
#include <iostream>

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<bool> stack(nums.size(), false);
        
        for (int i = 0; i < nums.size(); ++i) {
            if (dfs(nums, nums[i], i, visited, stack)) {
                return true;
            }
        }
        return false;
    }

    bool dfs(vector<int>& nums, int direction, int index, vector<bool>& visited, vector<bool>& stack) {
        
        int nextIndex = (int)(index + nums.size() + nums[index]%(int)nums.size()) % nums.size();
        /*
        cout << "index: " << index << " netIndex: " << nextIndex << endl;
        cout << "stack:";
        for (bool b : stack) {
            cout << b << " " ;
        }
        cout << endl;
        
        cout << "visited:";
        for (bool b : visited) {
            cout << b << " " ;
        }
        cout << endl;
         */
        
        if (stack[index] && index != nextIndex) {
            return true;
        }
        
        if (visited[index]) {
            return false;
        }
        
        if (nums[index] * direction < 0) {
            return false;
        }
        
        visited[index] = true;
        stack[index] = true;
        bool subB = dfs(nums, nums[index], nextIndex, visited, stack);
        stack[index] = false;
        
        return subB;
    }
};

/*
int main(int argc, const char * argv[]) {
    
    vector<int> input = {-1,-1,-1};
    bool target = true;
    Solution sol;
    bool ret = sol.circularArrayLoop(input);
    
    assert(ret == target);
    return 0;
    
}
 */
