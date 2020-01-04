//
//  a509FibonacciNumber.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/4/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int N) {
        if (N <= 1) return N;
        vector<int> mem(N+1, -1);
        mem[0] = 0;
        mem[1] = 1;
        
        fib_sub(mem, N);
        
        return mem[N];
    }
    
    void fib_sub(vector<int>& mem, int N) {
        if (mem[N] != -1) return;
        
        fib_sub(mem, N-1);
        fib_sub(mem, N-2);
        
        mem[N] = mem[N-1] + mem[N-2];
    }
};
