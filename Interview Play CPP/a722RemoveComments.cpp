//
//  a722RemoveComments.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/25/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> response;
        
        bool block_comment_mode = false;
        string newLine = "";
        
        for(auto &line : source) {
            if(!block_comment_mode) {
                newLine = "";
            }
            
            for(int i = 0; i < line.size(); i++) {
                if(line[i] == '/') {
                    if(i < line.size() - 1) {
                        if(line[i+1] == '*' && !block_comment_mode) {
                            block_comment_mode = true;
                            i++;
                            continue;
                        }
                        if(!block_comment_mode && line[i+1] == '/') {
                            break;
                        }
                    }
                }
                if(line[i] == '*') {
                    if(i < line.size() - 1 && line[i+1] == '/') {
                        if(block_comment_mode) {
                            block_comment_mode = false;
                            i++;
                            continue;
                        }
                    }
                }
                
                if(!block_comment_mode) {
                    newLine.push_back(line[i]);
                }
            }
            if(newLine.size() > 0 && !block_comment_mode) {
                response.push_back(newLine);
            }
        }
        
        return response;
    }
};
