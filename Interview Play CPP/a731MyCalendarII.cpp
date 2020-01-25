//
//  a731MyCalendarII.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/24/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <map>

using namespace std;

class MyCalendarTwo {
    private:
        map<int, int> m;
    public:
        
        //Parameter n sets the max number of bookings allowed to overlap
        //if n is set to 1 if will check for double booking
        //if n is set to 2 if will check for triple booking etc
        bool canAdd(int n){
            int count = 0;
            for (auto entry: m){
                count+=entry.second;
                if(count>n) return false;
            }
            return true;
        }
        
        bool book(int start, int end) {
            m[start]++;
            m[end]--;
            if(canAdd(2)) return true;//Check for triple booking (n=2)
            else{//restore the original counts since we are not booking this room
                m[start]--;
                m[end]++;
                return false;
            }
        }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
