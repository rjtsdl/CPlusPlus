//
//  a1182ShortestDistancetoTargetColor.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/24/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>&arr, vector<vector<int>>&que) {
        int n=arr.size(),i,j,k,color;
        vector<int>res(que.size(),-1);
        vector<vector<int>>left(4,vector<int>(n,-1));
        vector<vector<int>>right(4,vector<int>(n,-1));
        for(color=1;color<=3;color++)//
        {
            if(arr[0]==color)
                   left[color][0]=0;
            
            for(j=1;j<n;j++)
            {
                 if(arr[j]==color)
                 {
                     left[color][j]=0;
                 }
                 else if(left[color][j-1]!=-1)
                 {
                     left[color][j]=left[color][j-1]+1;
                 }
            }
        }
        
        for(color=1;color<=3;color++)
        {
            if(arr[n-1]==color)
                right[color][n-1]=0;
            for(j=n-2;j>=0;j--)
            {
                if(arr[j]==color)
                    right[color][j]=0;
                else if(right[color][j+1]!=-1)
                {
                    right[color][j]=right[color][j+1]+1;
                }
            }
        }
        
        // for(color=1;color<=3;color++)
        // {
        //     for(i=0;i<n;i++)
        //     {
        //         cout<<"color= "<<color<<" "<<left[color][i]<<"  "<<right[color][i]<<endl;
        //     }
        // }
        
        for(i=0;i<que.size();i++)
        {
            int idx=que[i][0];
            int color=que[i][1];
            //cout<<idx<<"  "<<color<<"  "<<left[color][idx]<<"  "<<right[color][i]<<endl;
            int x,y;
            x=left[color][idx];
            y=right[color][idx];
            if(x==-1||y==-1)
            {
                res[i]=max(x,y);
            }
            else
            {
                res[i]=min(x,y);
            }
            
        }
        return res;
    }
};
