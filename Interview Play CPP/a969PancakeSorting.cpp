//
//  a969PancakeSorting.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/22/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        for (int valueToSort = A.size(); valueToSort > 0; valueToSort--) {
            // locate the position for the value to sort in this round
            int index = find(A, valueToSort);

            // sink the value_to_sort to the bottom,
            // with at most two steps of pancake flipping.
            if (index == valueToSort - 1)
                continue;
            // 1). flip the value to the head if necessary
            if (index != 0) {
                ans.push_back(index + 1);
                reverse(A.begin(), A.begin()+index+1);
            }
            // 2). now that the value is at the head, flip it to the bottom
            ans.push_back(valueToSort);
            reverse(A.begin(), A.begin()+ valueToSort);
        }

        return ans;
        
    }

    int find(vector<int> a, int target) {
        for (int i = 0; i < a.size(); i++)
            if (a[i] == target)
                return i;
        return -1;
    }

};
