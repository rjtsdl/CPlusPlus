//
//  a957PrisonCellsAfterNDays.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        cout << "i = -1, key = " << getKey(cells) << endl;
        unordered_map<int, int> seen;
        int cycleLen = 0;
        int i = 0;
        for (i =0; i < N; ++i) {
            auto nextDay = nextDayState(cells);
            int nextDayKey = getKey(nextDay);
            cout << "i = " << i << ", key = " << nextDayKey << endl;
            if (seen.count(nextDayKey)) {
                cout << "seen on day : " << seen[nextDayKey] << endl;
                cout << "current i: " << i << endl;
                cycleLen = i - seen[nextDayKey];
                cout << "cycleLen: " << cycleLen << endl;
                break;
            }
            seen[nextDayKey] = i;
            cells = nextDay;
        }
        
        if (cycleLen) {
            N = (N - i -1) % cycleLen + i - cycleLen;
            for (auto s : seen) {
                if (s.second == N) {
                    cout << "the value of day: " << s.second << endl;
                    return getVector(s.first);
                }
            }
        }
        
        return cells;
        
    }
    
    vector<int> getVector(int key) {
        vector<int> res(8, 0);
        for (int i = 0; i < 8; ++i) {
            res[7-i] = (key & (1 << i)) >> i;
        }
        return res;
    }
    
    int getKey(vector<int> cells) {
        int res = 0;
        for (int c : cells) {
            res = res << 1;
            res += c;
        }
        return res;
    }
    
    vector<int> nextDayState(const vector<int>& cells) {
        vector<int> res(8,0);
        for (int i = 1; i <= 6; ++i) {
            res[i] = cells[i-1] == cells[i+1] ? 1 : 0;
        }
        return res;
    }
};

/*
int main() {
    vector<int> in{1,0,0,1,0,0,1,0};
    int N = 1000000000;
    
    Solution* sol = new Solution();
    sol->prisonAfterNDays(in, N);
    return 0;
}
 */
