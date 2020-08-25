//
//  a489RobotRoomCleaner.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/25/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation */
  class Robot {
    public:
      // Returns true if the cell in front is open and robot moves into the cell.
      // Returns false if the cell in front is blocked and robot stays in the current cell.
      bool move();
 
      // Robot will stay in the same cell after calling turnLeft/turnRight.
      // Each turn will be 90 degrees.
      void turnLeft();
      void turnRight();
 
      // Clean the current cell.
      void clean();
  };
 

class Solution {
public:

    void goBack(Robot& robot) {
      robot.turnRight();
      robot.turnRight();
      robot.move();
      robot.turnRight();
      robot.turnRight();
    }

    void backtrack(Robot& robot, int row, int col, int d, vector<vector<int>>& directions, set<vector<int>>& visited) {
        visited.insert({row, col});
        robot.clean();
          // going clockwise : 0: 'up', 1: 'right', 2: 'down', 3: 'left'
          for (int i = 0; i < 4; ++i) {
            int newD = (d + i) % 4;
            int newRow = row + directions[newD][0];
            int newCol = col + directions[newD][1];

            if (!visited.count({newRow, newCol}) && robot.move()) {
              backtrack(robot, newRow, newCol, newD, directions, visited);
              goBack(robot);
            }
            // turn the robot following chosen direction : clockwise
            robot.turnRight();
          }
    }
    void cleanRoom(Robot& robot) {
        // going clockwise : 0: 'up', 1: 'right', 2: 'down', 3: 'left'
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        set<vector<int>> visited;
        backtrack(robot, 0, 0, 0, directions, visited);
    }
};
