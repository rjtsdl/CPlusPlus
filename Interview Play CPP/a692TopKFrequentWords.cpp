//
//  a692TopKFrequentWords.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/11/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordCount;
        for (string s: words) {
            wordCount[s]++;
        }
        
        auto comp = [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        };
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);
        
        
        for (auto kv: wordCount) {
            pq.push(make_pair(kv.second, kv.first));
            while (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<string> ret;
        while (!pq.empty()) {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
