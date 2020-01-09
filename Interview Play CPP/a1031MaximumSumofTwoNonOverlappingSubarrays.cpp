//
//  a1031MaximumSumofTwoNonOverlappingSubarrays.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/9/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        return max(maxSumTwoNoOverlapHelper(A, L, M), maxSumTwoNoOverlapHelper(A, M, L));
     
     }
    int maxSumTwoNoOverlapHelper(vector<int>& A, int L, int M) {
        deque<int> lque;
        deque<int> mque;
        
        int lsum=0;
        int msum=0;
        
        int lmax=0;
        int mmax=0;
        
        int total = 0;
        
        int i = 0;
        while(i < L+M) {
            if (i<L) {
                lque.push_back(A[i]);
                lsum += A[i];
            } else {
                mque.push_back(A[i]);
                msum += A[i];
            }
            ++i;
        }
        
        total = lsum + msum;
        lmax = lsum;
        mmax = msum;
        
        while(i < A.size()) {
            
            int lleft = lque.front(); lque.pop_front();
            int mleft = mque.front(); mque.pop_front();
            lque.push_back(mleft);
            mque.push_back(A[i]);
            
            lsum += mleft - lleft;
            msum += A[i] - mleft;
            
            lmax = max(lmax, lsum);
            
            total = max(total, lmax + msum);
            ++i;
        }
        
        return total;
    }
};
