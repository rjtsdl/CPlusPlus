//
//  bit.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include "bit.hpp"
#include <iostream>

BIT::BIT(vector<int> arr) {
    m_bits = vector<int>(arr.size()+1, 0);
    /*
    for (int i = 0; i < arr.size(); ++i) {
        this->update(i+1, arr[i]);
    }*/
}

void BIT::update(int i, int increment) {
    while (i > 0) {
        m_bits[i] += increment;
        cout << i <<":" <<endl;
        i -= i & (-i);
    }
}

int BIT::search(int i) {
    int count = 0;
    while (i < m_bits.size()) {
        count += m_bits[i];
        i += i & (-i);
    }
    
    return count;
}

void BIT::print() {
    cout << "BIT table" << endl;
    for (int i =0; i<m_bits.size(); ++i) {
        cout << i << ": " << m_bits[i] << endl;
    }
}





