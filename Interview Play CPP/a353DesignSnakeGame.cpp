//
//  a353DesignSnakeGame.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <list>

using namespace std;

class SnakeGame {
private:
    int m_width;
    int m_height;
    list<vector<int>> m_snake;
    set<vector<int>> m_snakeSet;
    vector<vector<int>> m_food;
    int m_foodIdx;
    
    
    
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        m_width = width;
        m_height = height;
        m_food = food;
        m_foodIdx = 0;
        
        m_snake.push_back({0,0});
        m_snakeSet.insert({0,0});
        
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        vector<int> nextHead = m_snake.front();
        switch (direction[0]) {
            case 'U':
                nextHead[0]--;
                break;
            case 'L':
                nextHead[1]--;
                break;
            case 'R':
                nextHead[1]++;
                break;
            case 'D':
                nextHead[0]++;
                break;
            default:
                break;
        }
        
        if (nextHead[0] <0 || nextHead[0] >= m_height || nextHead[1] < 0 || nextHead[1] >= m_width) {
            return -1;
        }
        
        if (m_foodIdx < m_food.size() && m_food[m_foodIdx][0] == nextHead[0] && m_food[m_foodIdx][1] == nextHead[1]){
            m_snake.push_front(nextHead);
            m_snakeSet.insert(nextHead);
            m_foodIdx++;
            return m_snake.size()-1;
        }
        
        vector<int> tail = m_snake.back();
        m_snake.pop_back();
        m_snakeSet.erase(tail);
        
        if (m_snakeSet.find(nextHead) != m_snakeSet.end()) {
            return -1;
        }
        
        m_snake.push_front(nextHead);
        m_snakeSet.insert(nextHead);
        return m_snake.size()-1;
        
    }
};
