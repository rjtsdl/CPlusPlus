//
//  a295FindMedianfromDataStream.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

// for the advanced if number [0, 100]

class MedianFinder {
    vector<int>_hisG;
    
    int _hd;
    int _hm;
    int _ld;
    int _lm;
    
public:
    /** initialize your data structure here. */
    MedianFinder() : _hisG(101, 0){
        _hd = 0;
        _hm = 0;
        _ld = 0;
        _lm = 100;
    }
    
    void addNum(int num) {
        _hisG[num]++;
        if (num >= _hm) {
            _hd++;
        } else {
            _hd--;
        }
        
        while ((_hm >=0 && _hm<=100) && (_hd- 2*_hisG[_hm] >=0) || _hd < 0) {
            if (_hd < 0) {
                _hd += 2*_hisG[_hm--];
            } else {
                _hd -= 2*_hisG[_hm++];
            }
        }
        
        if (num <= _lm) {
            _ld++;
        } else {
            _ld--;
        }
        
        while ((_lm >= 0 && _lm <= 100) && (_ld-2*_hisG[_lm]>=0) || _ld <0) {
            if (_ld < 0) {
                _ld += 2*_hisG[_lm++];
            } else {
                _ld -= 2*_hisG[_lm--];
            }
        }
    }
    
    double findMedian() {
        return 0.5* _lm + 0.5*_hm;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
