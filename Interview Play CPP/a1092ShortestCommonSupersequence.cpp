//
//  a1092ShortestCommonSupersequence.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/2/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string X, string Y) {
        int m = X.size();
        int n = Y.size();
        int t[m+1][n+1];
        for( int i = 0 ; i <= m ; i++ ){
            for( int j = 0 ; j <= n ; j++){
                if( i==0 || j==0 )
                    t[i][j] = 0;
                else if ( X[i - 1] == Y[j - 1])
                    t[i][j] = t[i - 1][j - 1] + 1;
                else
                    t[i][j] = max( t[i-1][j] , t[i][j-1]);
            }
        }

        int i=m;
        int j=n;
        string s="";
        while( i>0 && j>0 ){
            if( X[i-1] == Y[j-1]){
                s.push_back( X[i-1] );
                i--;
                j--;
            }
            else{
                if( t[i][j-1] > t[i-1][j]){
                    s.push_back( Y[j-1] );
                    //s.push_back(Y[j - 1]);
                    j--;
                }

                else{
                    //s.push_back( X[i-1] );
                    s.push_back( X[i-1] );
                    i--;
                }

            }

        }
        while (i > 0)
        {
            s.push_back(X[i - 1]);
            i--;
        }
        while (j > 0)
        {
            s.push_back(Y[j - 1]);
            j--;
        }
        reverse(s.begin(),s.end());

        return s;
    }
};
