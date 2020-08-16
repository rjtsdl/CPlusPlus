//
//  a1396DesignUndergroundSystem.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> idstart;
        unordered_map<string,unordered_map<string,vector<int>>> startend;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        idstart[id]=make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int> is=idstart[id];
        unordered_map<string,vector<int>> existing=startend[is.first];
        existing[stationName].push_back(t-is.second);
        startend[is.first]=existing;
    }
    
    double getAverageTime(string startStation, string endStation) {
        unordered_map<string,vector<int>> existing= startend[startStation];
            int sum = std::accumulate(existing[endStation].begin(),existing[endStation].end(), 0);
        return sum/((double)existing[endStation].size());
    }
};
