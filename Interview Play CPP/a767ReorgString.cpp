//
//  a767ReorgString.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/15/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int fre[26] = {0};
        for(char c : s){
            fre[c-'a']++;
        }
        priority_queue<pair<int, char>>q;
        for(int i = 0; i < 26; i++){
            if(fre[i] != 0){
                q.push({fre[i], 'a'+i});
            }
        }
        
        string ans = "";
        while(!q.empty()){
            int cnt1 = q.top().first;
            char c1 = q.top().second;
            q.pop();
            if(!q.empty()){
                int cnt2 = q.top().first;
                char c2 = q.top().second;
                q.pop();
                ans += c1;
                ans += c2;
                cnt1--;
                cnt2--;
                if(cnt1){
                    q.push({cnt1, c1});
                }
                if(cnt2){
                    q.push({cnt2, c2});
                }
                continue;
            }
            if(ans.size() > 0 && ans[ans.size()-1] == c1){
                return "";
            }
            ans += c1;
            cnt1--;
            if(cnt1){
                q.push({cnt1, c1});
            }
        }
        return ans;
    }
};
