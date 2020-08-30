//
//  a932BeautifulArray.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    
    map<int, vector<int>> m_mem;
public:
    vector<int> beautifulArray(int N) {
        m_mem[0] = {};
        m_mem[1] = {1};
        
        helper(N);
        return m_mem[N];
    }
    
    void helper(int N) {
        if (m_mem.find(N) != m_mem.end()) return;
        int odd = (N+1)/2;
        int even = N/2;
        
        helper(odd);
        helper(even);
        
        vector<int> res;
        
        for(int i : m_mem[odd]) {
            m_mem[N].push_back(2*i -1);
        }
        
        for (int i : m_mem[even]) {
            m_mem[N].push_back(2*i);
        }
        
        return;
        
    }
};
