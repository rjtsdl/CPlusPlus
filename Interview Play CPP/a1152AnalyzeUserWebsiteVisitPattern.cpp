//
//  a1152AnalyzeUserWebsiteVisitPattern.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/15/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
/*
using namespace std;
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<pair<int, string>>> myMap;
        set<vector<string>> seqs;
        map<vector<string>, int> seqCount; // using map instead of unordered_map so that vector<> can be used as key

        // Generate map of username to (timestamp, website) pair
        for (int i=0; i<username.size(); i++) myMap[username[i]].push_back(make_pair(timestamp[i], website[i]));
        
        for (auto iter : myMap) {
            // sort the visits of each user by timestamp
            vector<pair<int, string>> visits = iter.second;
            sort(visits.begin(), visits.end(), [](pair<int, string>& a, pair<int, string>& b) {
                return (a.first < b.first);
            });
            
            // generate all possible 3-sequences of the websites for each user
            seqs.clear(); // this needs to be a set since we can have websites which repeat
            for (int i=0; i<visits.size(); i++) {
                for (int j=0; j<i; j++) {
                    for (int k=0; k<j; k++) {
                        seqs.insert({visits[k].second, visits[j].second, visits[i].second});
                    }
                }
            }
            
            // increment the count of each 3-sequence of websites
            for (vector<string> seq : seqs) seqCount[seq]++;
        }
        
        // note: if we needed the top K tuples, we could have used a priority_queue
        // But max_element suffices here because we only need the most frequent tuple
        
        return max_element(seqCount.begin(), seqCount.end(), [](pair<vector<string>, int>& p1, pair<vector<string>, int>& p2){
            // 1. if the counts of the 2 tuples are different, sort by whichever is greater : return (p1.second < p2.second);
            // 2. if the counts are equal, then sort by whichever comes first alphabetically: return (p1.first > p2.first);
            
            return ((p1.second == p2.second) ? (p1.first > p2.first) : (p1.second < p2.second));
        })->first;
    }
};
 */



