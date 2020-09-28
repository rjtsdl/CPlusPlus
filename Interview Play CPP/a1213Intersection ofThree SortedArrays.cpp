//
//  a1213Intersection ofThree SortedArrays.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/27/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> answer;
        int one = 0;
        int two = 0;
        int three = 0;
        
        while(one < arr1.size() && two < arr2.size() && three < arr3.size()){
            int minEle = min(arr1[one], min(arr2[two], arr3[three]));
            if(arr1[one] ==  arr2[two] && arr1[one] ==  arr3[three])
                answer.push_back(arr1[one]);
            
            if(arr1[one] == minEle)
                one++;
            if(arr2[two] == minEle)
                two++;
            if(arr3[three] == minEle)
                three++;
        }
        return answer;
    }
};
