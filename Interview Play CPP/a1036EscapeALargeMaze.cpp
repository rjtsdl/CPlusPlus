//
//  a1036EscapeALargeMaze.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>
#include <map>

using namespace std;
/*
class Solution {
    int y_len;
    int x_len;

    map<int, map<int, bool> > m_Visited;
    int dist;
    list< pair<int, int>> m_Queue;
    pair<int, int>      _end;
    pair<int, int>      _start;

    set <pair<int, int> > _block;
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& start, vector<int>& target){
        bool res = false;

        x_len = 1000000;
        y_len = 1000000;

        m_Visited[start[0]][start[1]] = true;
        _start = pair<int, int>(start[0], start[1]);
        _end = pair<int, int>(target[0], target[1]);

        for (const vector<int> & p : blocked){
            pair<int, int> t = pair<int, int>(p[0], p[1]);
            _block.insert(t);
        }

        m_Queue.push_front(_start);
        res = makeMoves(_start);

        if (res){
            printf("%s", "\n");
            m_Queue.clear();
            m_Queue.push_front(_end);
            res = makeMoves(_end);
        }
        return res;
    }
    
    bool makeMoves(pair<int, int>  & to){
        bool res = false;
        while (m_Queue.size() && res == false){
            pair<int, int> & _from = *m_Queue.begin();
            res = MoveOne(_from, to, 'l') ||
                MoveOne(_from, to, 'u') ||
                MoveOne(_from, to, 'd') ||
                MoveOne(_from, to, 'r');
            m_Queue.pop_front();
        }
        return res;
    }
    
    bool MoveOne(pair<int, int> & from, pair<int, int> to, char pos){
        bool res = false;
        int idy = from.second;
        int idx = from.first;

        pair<int, int> & end = (to == _start) ? _end : _start;

        bool bMoved = false;
        switch (pos){
        case 'l':
            while (maze(idx - 1, idy) != 1 && abs(from.first - idx) <= 200){
                idx--;
                bMoved = true;
            }
            break;
        case 'r':
            while (maze(idx + 1, idy) != 1 && abs(from.first - idx) <= 200){
                idx++;
                bMoved = true;
            }
            break;
        case 'u':
            while (maze(idx, idy + 1) != 1 && abs(from.second - idy) <= 200){
                idy++;
                bMoved = true;
            }
            break;
        case 'd':
            while (maze(idx, idy - 1) != 1 && abs(from.second - idy) <= 200){
                idy--;
                bMoved = true;
            }
            break;
        }

        pair<int, int> new_pos = pair<int, int>(idx, idy);
        int current_dist = getDistance(new_pos, to);
        if (bMoved &&
            m_Visited[idx][idy] == false &&
            current_dist <= 200){
            m_Queue.push_back(new_pos);
            m_Visited[idx][idy] = true;
        }
        if (current_dist > 200 || new_pos == end){
            res = true;
        }
        return res;
    }
    
    int maze(int x, int y){
        if (x < 0) return 1;
        else if (x > 1000000) return 1;
        if (y < 0) return 1;
        else if (y > 1000000) return 1;
        pair<int, int> xy = pair<int, int>(x, y);
        if (_block.find(xy) != _block.end())
            return 1;
        return 0;
    }
    
    int getDistance(pair<int, int> &one, pair<int, int> & two){
        int xdist = abs(one.first - two.first);
        int ydist = abs(one.second - two.second);
        int dist = sqrt(xdist*xdist + ydist*ydist);
        return dist;
    }
    
    int max(int a, int b){
        return a >= b ? a : b;
    }
};
 */
