//
//  a1538GuesstheMajorityinaHiddenArray.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int guessMajority(ArrayReader &reader) {
        int n = reader.length();
        unordered_map<int,int> m;
        
        //map<int,int> m;
        m[0] = 1;
        int a = reader.query(0,1,2,3);
        int e = reader.query(1,2,3,4); m[4] = a==e?1:2;
        int b = reader.query(0,2,3,4); m[1] = b==e?1:2;
        int c = reader.query(0,1,3,4); m[2] = b==c?m[1]:3-m[1];
        int d = reader.query(0,1,2,4); m[3] = c==d?m[2]:3-m[2];
        int count1 = 0, count2 = 0;
        int id1 = -1, id2 =-1;
        int res = -1;
        for(int i=0;i<5;i++) {
            if(m[i] == 1) {
                count1++; id1 = i;
            }
            else {
                count2 ++; id2= i;
            }
        }
        int last = e;
        for(int i=5;i<n;i++){
            int cur = reader.query(i-3,i-2,i-1,i);
            m[i] = cur == last? m[i-4]:(3-m[i-4]);
            last = cur;
            if(m[i] == 1) {
                count1++; id1 = i;
            }
            else {
                count2 ++; id2= i;
            }
        }
        // cout<<count1<<" "<<count2<<endl;
        // for(auto x:m){
        //     cout<<x.second<<" ";
        // }
        cout<<endl;
        if(count1 == count2) return -1;
        return count1 > count2? id1:id2;
    }
        
};
