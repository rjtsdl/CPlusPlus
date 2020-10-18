//
//  a855ExamRoom.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <set>
#include <vector>

using namespace std;


class ExamRoom {
public:
    int n;
    set<int> cur;
    set<pair<int, int>, greater<pair<int, int>>> cand;
    ExamRoom(int N) {
        n = N;
    }
    
    void add_candidate(int a, int b) {
        int next_idx = (a + b) / 2;
        if (next_idx != a) {
            cand.emplace(min(abs(b - next_idx), abs(a - next_idx)), -next_idx);
        }
    }
    
    void delete_candidate(int a, int b) {
        int next_idx = (a + b) / 2;
        if (next_idx != a) {
            auto p = make_pair(min(abs(b - next_idx), abs(a - next_idx)), -next_idx);
            cand.erase(p);
        }
    }
    
    int seat() {
        if (cur.empty()) {
            cur.insert(0);
            cand.emplace(n - 1, -(n - 1));
            return 0;
        }
        auto [len, idx] = *cand.begin();
        idx = -idx;
        cand.erase(cand.begin());
        auto next = cur.upper_bound(idx);
        if (next != cur.end()) {
            add_candidate(idx, *next);
        }
        auto prev = cur.upper_bound(idx);
        if (prev != cur.begin()) {
            prev--;
            add_candidate(*prev, idx);
        }
        cur.insert(idx);
        return idx;
        
    }
    
    void leave(int p) {
        cur.erase(p);
        if (cur.empty()) {
            cand.clear();
            return;
        }
        int next_idx = -1, prev_idx = -1;
        auto next = cur.upper_bound(p);
        if (next != cur.end()) {
            next_idx = *next;
            delete_candidate(p, *next);
        }
        auto prev = cur.upper_bound(p);
        if (prev != cur.begin()) {
            prev--;
            prev_idx = *prev;
            delete_candidate(*prev, p);
        }
        if (cur.size() == 1) {
            cand.clear();
            int idx = *cur.begin();
            if (idx != 0)
                cand.emplace(idx, 0);
            if (idx != n - 1)
                cand.emplace(n - 1 - idx, -(n - 1));
            return;
        }
        if (p == 0) {
            cand.emplace(*cur.begin(), 0);
        } else if (p == n - 1) {
            cand.emplace(n - 1 - *cur.rbegin(), -(n - 1));
        } else {
            if (next_idx >= 0 && prev_idx >= 0) {
                add_candidate(prev_idx, next_idx);
            }
        }
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
