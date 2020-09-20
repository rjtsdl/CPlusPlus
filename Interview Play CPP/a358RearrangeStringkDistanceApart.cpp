//
//  a358RearrangeStringkDistanceApart.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/19/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string rearrangeString(string s, int k) {
        int cnt[26] = {};
        priority_queue<pair<int, int>> pq;
        queue<pair<int, int>> q;
        for (auto ch : s)
            ++cnt[ch - 'a'];
        for (auto i = 0; i < 26; ++i)
            if (cnt[i] != 0)
                pq.push({cnt[i], i});
        string res = "";
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            res += 'a' + p.second;
            q.push({p.first - 1, p.second});
            if (q.size() >= k) {
                auto p = q.front(); q.pop();
                if (p.first)
                    pq.push({p.first, p.second});
            }
        }
        return res.size() == s.size() ? res : "";
    }
};
