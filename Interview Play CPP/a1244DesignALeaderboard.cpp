//
//  a1244DesignALeaderboard.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/25/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

class Leaderboard {
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        setScore(playerId, m2[playerId]+score);
    }
    
    int top(int K) {
        int sum = 0;
        auto it = m1.begin();
        while(K>0){
            int score = it->first, n = it->second.size();
            int nToAdd = min(K, n);
            K -= nToAdd;
            sum += score * nToAdd;
            ++it;
        }
        return sum;
    }
    
    void reset(int playerId) {
        setScore(playerId, 0);
    }
    
    void setScore(int id, int score){
        int preScore = m2[id];
        if(auto it1 = m1.find(preScore); it1 != m1.end()) it1->second.erase(id);
        m1[score].insert(id);
        m2[id] = score;
    }
    
    map<int, set<int>, greater<int>> m1; //score, set<id>
    unordered_map<int, int> m2; //id score
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
