//
//  a422ValidWordSquare.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/19/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
            //Iterate through all words.
            for(int i = 0; i < words.size(); i++)
            {
                int j = 0;
                
                //Check in other words the ith char should be same as the jth char in curr word.
                for(int k = 0; j < words[i].size() && k < words.size(); j++, k++)
                {
                    if(words[i][j] != words[k][i])
                        return false;
                }
                
                //Check if we reach till the end of ith word.
                if(j != words[i].size())
                    return false;
            }
            
            return true;
        }
};
