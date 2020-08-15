//
//  a472ConcatenatedWords.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/15/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string,int> mp;
    bool canform(int start,int stop,string s)
    {
        if(start>stop) return true;
        string s2=s.substr(start,stop-start+1);
        if(mp.find(s2)!=mp.end()) return mp[s2];
        for(int i=start;i<=stop;i++)
        {
            string s1=s.substr(start,i-start+1);
            string s2=s.substr(i+1,stop-i);
            if(mp.find(s1)!=mp.end())
            {
                if(canform(i+1,stop,s))
                {
                    mp[s]=1;
                    mp[s1]=1;
                    mp[s2]=1;
                    return mp[s];
                }
            }
        }
        return 0;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &s1 ,string &s2)
        {
            return s1.length()<s2.length();
        });
        mp.clear();
        mp[words[0]]=1;
        vector<string> ans;
        for(int i=1;i<words.size();i++)
        {
            if(canform(0,words[i].length()-1,words[i]))
            {
                ans.push_back(words[i]);
            }
            mp[words[i]]=1;
            
        }
        return ans;
    }
};
