//
//  a1329SortTheMatrixDiagonally.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/28/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrix;
    map<pair<int,int>,bool> visited;
    vector<pair<int,int>> positions;
    vector<int> getDiagonalArray(int r,int c)
    {
        vector<int> nums;
    
        while(r<matrix.size()&&c<matrix[0].size())
        {
            positions.push_back(pair<int,int>(r,c));
            nums.push_back(this->matrix[r][c]);
            visited[pair<int,int>(r,c)]=true;
        ++r;
        ++c;
        }
        return nums;
        
    }
    
    void sortAndStore(vector<int> result,vector<pair<int,int>> positions)
    {
        sort(result.begin(),result.end());
        for(int r=0;r<positions.size();++r)
        {
            this->matrix[positions[r].first][positions[r].second]=result[r];
        }
        
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if(mat.size()==1||mat[0].size()==1)return mat;
        int r=0;
        int c=0;
        vector<int> result;
        this->matrix=mat;
        while(r<mat.size())
        {
            c=0;
            while(c<mat[0].size())
            {
            pair<int,int> p(r,c);
            if(visited[p]==false)
            {
             result=getDiagonalArray(r,c);
             sortAndStore(result,positions);
             positions.clear();
            }
            ++c;
            }
            
            ++r;
        }
        
        return this->matrix;
    }
};
