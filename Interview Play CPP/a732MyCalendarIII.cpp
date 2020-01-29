//
//  a732MyCalendarIII.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/24/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <map>

using namespace std;

class MyCalendarThree {
    map<int, int> m;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int count = 0, K = 0;
        m[start]++;
        m[end]--;
        for (auto entry: m){
            count+=entry.second;
            K = max(K, count);
        }
        return K;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
