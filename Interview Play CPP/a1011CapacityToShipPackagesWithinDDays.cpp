//
//  a1011CapacityToShipPackagesWithinDDays.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/26/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int sum = 0;
        int len = weights.size();
        
        for(int i=0;i<len;i++){
            sum+=weights[i];
        }
        
        int start=*max_element(weights.begin(),weights.end()),end=sum;
        int result = 0;
        
        while(start <= end){
            int mid = (start+end)/2;
            if(ispossible(weights,len,D,mid)){
                result = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return result;
    }
    
    bool ispossible(vector<int>& weights,int len,int D,int min){
        int currmin = 0,days=1;
        for(int i=0;i<len;i++){
            if(currmin + weights[i] > min){
                currmin = weights[i];
                days++;
            }
            else{
                currmin += weights[i];
            }
        }
        if(days>D)
            return false;
        return true;
    }
};
