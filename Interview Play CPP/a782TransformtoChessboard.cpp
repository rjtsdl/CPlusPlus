//
//  a782TransformtoChessboard.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

/*
There are 2 properties which are invariant under transpositions of rows/columns:

The set { c(i), i ∈ {0,1,...,n-1} }, where c(i) is the count of 1s in column i, as well as the counts of columns for each value c in the set: #{ i ∈ {0,1,...,n-1} | c(i)=c }. Same for rows.
each pair of columns are either equal or are mutual n-bits binary complements. Same for rows.
From these observations we can construct a necessary and sufficient condition for any binary matrix to be transformable to a chessboard.

I use this to check whether or not a solution exists, then compute the optimal solution.
*/


class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        
        unsigned int n = board.size();
        unsigned int m = (1<<n)-1;
        
        // check if a solution exists.
        unsigned int x(0),y(0);
        unsigned int sum(0);unsigned int sum1(0);
        for(int j=0; j<n; ++j){
            sum += board[0][j];
            sum1 += board[j][0];
            x ^= (board[0][j] << j);
            y ^= (board[j][0] << j);
        }
        if(sum!=n/2 && (n%2==0 ||sum!=n/2+1) ||
            sum1!=n/2 && (n%2==0 ||sum1!=n/2+1)){
            return -1;
        }
        
        for (int i = 1; i < n; ++i){
            unsigned int t(0);
            for(int j=0; j<n; ++j){
                t ^= (board[i][j] << j);
            }
            if(x!=t && t!=m-x){             // every row must be equal to either x or x's n-bits binary complement.
                return -1;
            }
        }
        
        // From this point we know a solution exists: compute the optimal solution.
        unsigned int p[2] = {m/3,m-m/3};            // {01010..., 10101...} on n bits.
        unsigned int c[2] = {0,0};                  // c[i]: 2 times the minimal # of transpositions from x to p[i].
        
        for(int i=0; i<2; ++i){
            unsigned int t = x^p[i];
            while(t){
                c[i] += t&1;
                t>>=1;
            }
            if(c[i]%2==1){                  // invalid choice: cannot find permutation from x to p[i].
                c[i]=n;
            }
        }
        int count = std::min(c[0],c[1])/2;  // minimal # columns transpositions.
        
        c[0]=0;c[1]=0;
        for(int i=0; i<2; ++i){
            unsigned int t = y^p[i];
            while(t){
                c[i] += t&1;
                t>>=1;
            }
            if(c[i]%2==1){
                c[i]=n;
            }
        }
        
       count += std::min(c[0],c[1])/2; // adding minimal # rows transpositions.
       return count;
       
    }
};
