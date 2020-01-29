//
//  a42TrappingRainWater.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/28/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> nonacs;
        int i = 0;
        int water = 0;
        
        while (i < height.size() ) {
            if (nonacs.empty() || height[i] < height[nonacs.top()] ) {
                nonacs.push(i++);
            } else if (height[i] > height[nonacs.top()]) {
                int hi = nonacs.top();
                int h = height[hi];
                nonacs.pop();
                water +=  (nonacs.empty() ? 0 : (i-nonacs.top()-1)) * min ( height[i] - h, nonacs.empty()? 0: height[nonacs.top()] - h);
                cout << "idx" << i << " water: " << water << endl;
            } else {
                nonacs.pop();
            }
        }
        
        return water;
    }
    /*
     Two pointers
     
     int trap(vector<int>& height)
     {
         int left = 0, right = height.size() - 1;
         int ans = 0;
         int left_max = 0, right_max = 0;
         while (left < right) {
             if (height[left] < height[right]) {
                 height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                 ++left;
             }
             else {
                 height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                 --right;
             }
         }
         return ans;
     }
     */
    
    /*
     Use stack to store the indices of the bars.
     Iterate the array:
     While stack is not empty and \text{height}[current]>\text{height}[st.top()]height[current]>height[st.top()]
     It means that the stack element can be popped. Pop the top element as \text{top}top.
     Find the distance between the current element and the element at top of stack, which is to be filled. \text{distance} = \text{current} - \text{st.top}() - 1distance=current−st.top()−1
     Find the bounded height \text{bounded\_height} = \min(\text{height[current]}, \text{height[st.top()]}) - \text{height[top]}bounded_height=min(height[current],height[st.top()])−height[top]
     Add resulting trapped water to answer \text{ans} \mathrel{+}= \text{distance} \times \text{bounded\_height}ans+=distance×bounded_height
     Push current index to top of the stack
     Move \text{current}current to the next position
     */
    
    /*
     
     int trap(vector<int>& height)
     {
         int ans = 0, current = 0;
         stack<int> st;
         while (current < height.size()) {
             while (!st.empty() && height[current] > height[st.top()]) {
                 int top = st.top();
                 st.pop();
                 if (st.empty())
                     break;
                 int distance = current - st.top() - 1;
                 int bounded_height = min(height[current], height[st.top()]) - height[top];
                 ans += distance * bounded_height;
             }
             st.push(current++);
         }
         return ans;
     }
     */
};


int main()
{
    Solution sol;
    vector<int> test{5,2,1,2,1,5};
    int res = sol.trap(test);
    cout << "trap water : " <<  res << endl;
}
