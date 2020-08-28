//
//  a1007MinimumDominoRotationsForEqualRow.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/28/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int ans=INT_MAX;
        for(int i=1;i<=6;i++)
        {
            
            bool f=true;int a=0,b=0;
            for(int j=0;j<A.size();j++)
            {
                if(A[j]==i && B[j]==i)
                {
                    
                }
                else if(A[j]==i)
                {
                    a++;
                }else if(B[j]==i)
                {
                    b++;
                    
                }
                else
                {
                    f=false;
                    break;
                }
            }
            
            if(f==false)
                continue;
            
            if(f==true)
                ans=min(ans,min(a,b));
            
        }
        
        if(ans==INT_MAX)
            return -1;
        else return ans;
    }
};
