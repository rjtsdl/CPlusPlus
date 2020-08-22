//
//  a593ValidSquare.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/22/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    double dist(vector<int> &p1, vector<int> &p2){
        return (double)sqrt((double)pow((p1[0]-p2[0]),2) + (double)pow((p1[1]-p2[1]),2));
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        std::unordered_map<double,int> m;
        //calculate distance between all points
        m[dist(p1,p2)]++;
        m[dist(p1,p3)]++;
        m[dist(p1,p4)]++;
        m[dist(p2,p3)]++;
        m[dist(p2,p4)]++;
        m[dist(p3,p4)]++;
        //In a square all sides are equal and diagonal are equal. Return false, if there are more than 2 distances.
        if(m.size()>2)
            return false;
        //check if the frequency of distances is 2(diagonals) and 4(for sides)
        auto first = m.begin();
        auto second = std::next(first);
        if(first->second==2 && second->second==4)
            return true;
        if(first->second==4 && second->second==2)
            return true;
        return false;
    }
};
