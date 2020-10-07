//
//  a900RLEIterator.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/7/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class RLEIterator {
public:
    int i=0;
    vector<int> v;
    RLEIterator(vector<int>& A) {
        v=A;
    }
    int next(int n) {
        if(i>=v.size())
            return -1;
        if(n<=v[i])
        {
            v[i]-=n;
            return v[i+1];
        }
        int x=n-v[i];
        v[i]=0, i+=2;
        return next(x);
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
