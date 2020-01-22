//
//  bit.hpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#ifndef bit_hpp
#define bit_hpp

#include <stdio.h>
#include <vector>

using namespace std;

// Suffix sum instead of prefix sum
class BIT {
private:
    vector<int> m_bits;
    
public:
    BIT(vector<int> arr);
    void update(int i, int increment);
    int search(int i);
    void print();
};

#endif /* bit_hpp */
