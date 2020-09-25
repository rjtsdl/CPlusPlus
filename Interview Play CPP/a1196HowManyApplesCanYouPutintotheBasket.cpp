//
//  a1196HowManyApplesCanYouPutintotheBasket.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/25/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        int l = 0;
        int r = arr.size()-1;
        bool add = true;
        int totalsum = 0;
        while (l <= r){
            int m = (l +r) / 2;
            nth_element(arr.begin()+l,arr.begin()+m,arr.begin()+r+1);
            if (add){
                totalsum += currsum(arr,l,m);
            }else{
                totalsum -= currsum(arr,m+1,r+1);
            }
            if (totalsum == 5000){
                return m;
            }else if (totalsum < 5000){
                add = true;
                l = m+1;
            }else{
                add = false;
                r = m-1;
            }
        }
        return r+1;
    }
    int currsum (vector<int> & arr, int l, int m ){
        int sum=0;
        for (int i =l;i<=m;i++)sum+= arr[i];
        return sum;
    }
};



