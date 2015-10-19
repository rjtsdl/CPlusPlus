//
//  MedianTwoSortedArray.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 10/18/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class MedianTwoSortedArray
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int left1 = 0;
        int right1 = (int)nums1.size();
        
        int left2 = 0;
        int right2 = (int)nums2.size();
        
        while ( left1 <= right1 && left2 <= right2
               && right1 - left1 + right2 - left2 > 2)
        {
            // get rid of one smallest
            if (left1 < right1 && left2 < right2) {
                if (nums1[left1] < nums2[left2]) {
                    left1++;
                }
                else
                {
                    left2++;
                }
            }
            else if (left1 < right1)
            {
                left1++;
            }
            else
            {
                left2++;
            }
            
            // get rid of one biggest
            if (left1 < right1 && left2 < right2) {
                if (nums1[right1-1] < nums2[right2-1]) {
                    right2--;
                }
                else
                {
                    right1--;
                }
            }
            else if (left1 < right1)
            {
                right1--;
            }
            else
            {
                right2--;
            }
        }
        
        double sum = 0;
        int count = 0;
        
        while (left1 < right1) {
            sum += nums1[left1];
            left1++;
            count++;
        }
        
        while (left2 < right2) {
            sum += nums2[left2];
            left2++;
            count++;
        }
        return sum/count;
        
    }
};

int main()
{
    vector<int> nums1 = {};
    vector<int> nums2 = {2,3};
    MedianTwoSortedArray obj;
    obj.findMedianSortedArrays(nums1, nums2);
    return 0;
    
    

}
