//
//  a499TheMazeIII.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/20/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

class Node{
public:
    int x, y, dis; string path;
    Node(int _x, int _y, int _dis, string _path): x(_x), y(_y), dis(_dis) , path(_path){}
};
class myCmp{
public:
    bool operator()(Node* a , Node* b){
        return a->dis > b->dis;
    }
};
class Solution {
    vector<int> _hole;
    
    vector<vector<int>> off{ {0,1} , {1,0} , {0,-1} ,{-1,0}  };
    vector<string> offS{"r" , "d" , "l" , "u" };
    vector<int> helper(vector<vector<int>>& maze, int curX, int curY , int dir){
        int m=maze.size();
        int n=maze[0].size();
        int step=0;
        for(;;step++){
            curX += off[dir][0]; curY += off[dir][1];//合法，續加
            if( curX==_hole[0] && curY==_hole[1] ){
                return {curX, curY, step+1};
            }
            if( curX<0 || m<=curX || curY<0 || n<=curY || maze[curX][curY]==1 ){//不合法，返回上部，回傳
                curX -= off[dir][0]; curY -= off[dir][1]; //step--;
                return {curX, curY, step};
            }
        }
        return {-1,-1,-1};
    }
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        _hole = hole;
        int m= maze.size();
        if(m==0)return "impossible";
        int n= maze[0].size();
        if(n==0)return "impossible";
        vector<vector< pair<int,string> >> dis(m, vector< pair<int,string> >(n, make_pair(INT_MAX,"") ) );
        priority_queue< Node*, vector<Node*> , myCmp > pq;//myCmp可以用一樣，不用在這邊館lexicographically
        pq.push( new Node( ball[0] ,ball[1] , 0 , "" ) );
        while(!pq.empty()){
            auto cur=pq.top(); pq.pop();
            int curX=cur->x, curY=cur->y, curDis=cur->dis;
            string curPath=cur->path;
            if( cur->dis > dis[curX][curY].first  )continue;
            if( cur->dis == dis[curX][curY].first ){
                dis[curX][curY].second = min( dis[curX][curY].second , curPath );//check
            }else{
                dis[curX][curY].second = curPath;
                dis[curX][curY].first = curDis;
            }
            //向外，不管有沒有 relaxed, 進站
            for(int i=0;i<4;i++){
                auto nxys = helper(maze, curX, curY, i);
                if(nxys[2]==0)continue;
                pq.push( new Node( nxys[0] , nxys[1] , curDis + nxys[2]  ,  curPath+offS[i]  ) );
            }
        }
        return dis[ hole[0] ][ hole[1] ].first==INT_MAX?"impossible":dis[ hole[0] ][ hole[1] ].second;
    }
};
