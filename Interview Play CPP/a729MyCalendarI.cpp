//
//  a729MyCalendarI.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/24/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <utility>
#include <set>
#include <vector>

using namespace std;


class MyCalendar {
private:
    set<pair<int, int>> m_cal;
public:
    MyCalendar() {
        m_cal = set<pair<int, int>>();
        m_cal.clear();
    }
    
    bool book(int start, int end) {
        auto p = make_pair(start, end);
        auto it = m_cal.lower_bound(p);
        
        if (it != m_cal.end() &&it->first< end) {
            return false;
        }
        
        if (it != m_cal.begin() && prev(it)->second > start) {
            return false;
        }
        
        m_cal.insert(it, p);
        return true;
    }
};

// More to look https://leetcode.com/problems/meeting-rooms-ii/discuss/203658/HashMapTreeMap-resolves-Scheduling-Problem

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
