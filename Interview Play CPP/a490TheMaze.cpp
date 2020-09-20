//
//  a490TheMaze.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/19/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    bool isValid(vector<int>& start , vector<vector<int>>& maze)
    {
        if(start[0] >= 0 && start[0] < maze.size() && start[1] >= 0 && start[1] < maze[0].size() && maze[start[0]][start[1]] != 1)
        {
            return true;
        }
        
        return false;
    }
    
    bool foundPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, unordered_map<string , pair<int , int>>& dir,vector<vector<int>>& vis)
    {
        if(!isValid(start , maze) || vis[start[0]][start[1]])
        {
            return false;
        }
        
        if(start == destination)
        {
            return true;
        }
        vis[start[0]][start[1]] = 1;
        for(auto it = dir.begin() ; it != dir.end() ; it++)
        {
            pair<int,int> delta = it->second;
            vector<int> newPos = start;
            
            while(isValid(newPos , maze))
            {
                newPos[0] = newPos[0] + delta.first;
                newPos[1] = newPos[1] + delta.second;
            }
            
          
            // get last valid position
                newPos[0] = newPos[0] - delta.first;
                newPos[1] = newPos[1] - delta.second;
            
           
            if(isValid(newPos , maze) && foundPath(maze, newPos, destination, dir,vis))
            {
                return true;
            }
        }
        
        return false;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        unordered_map<string , pair<int , int>> dir;
        dir["LEFT"]  = make_pair(0 , -1);
        dir["RIGHT"] = make_pair(0 , 1);
        dir["UP"]    = make_pair(-1 , 0);
        dir["DOWN"]  = make_pair(1 , 0);
        
        vector<vector<int>> vis(maze.size() , vector<int> (maze[0].size() , 0) );
        return foundPath(maze , start , destination, dir, vis);
        
    }
};
