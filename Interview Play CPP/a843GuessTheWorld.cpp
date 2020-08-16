//
//  a843GuessTheWorld.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/15/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

/*
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        while(1){
            int ptr = rand() % wordlist.size();
            int match = master.guess(wordlist[ptr]);
            if(match == 6)return;
            vector<string> tmp;
            for(int i=0; i<wordlist.size(); i++){
                int cnt = 0;
                for(int j=0; j<6; j++){
                    if(wordlist[i][j] == wordlist[ptr][j])cnt++;
                }
                if(cnt == match)tmp.push_back(wordlist[i]);
            }
            wordlist = tmp;
        }
        
    }
};
 */
