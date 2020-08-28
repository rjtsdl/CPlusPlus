//
//  a567PermutationInString.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/27/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1 == "")
            return true;
        if(s2 == "")
            return false;
        
        int n = s1.length(), m = s2.length();
        
        if(n > m)
            return false;
        
        vector<int> v1(26,0), v2(26,0);
        for(int i=0; i<n; i++)
        {
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        
        int c = 0;
        for(int i=0; i<26; i++)
            if(v1[i] == v2[i])
                c++;
        
        for(int i=0; i<m-n; i++)
        {
            if(c == 26)
                return true;
            
            int l = s2[i]-'a';
            int r = s2[i+n]-'a';
            
            //for declined char
            v2[l]--;
            if(v2[l] == v1[l])      //if now both freq have become equal
                c++;
            else if(v2[l]+1 == v1[l])   //if before updation they were equal
                c--;
            //if not equal before & after updation then continue
            
            
            //for just included char
            v2[r]++;
            if(v2[r] == v1[r])      //if now both freq have become equal
                c++;
            else if(v2[r]-1 == v1[r])   //if before updation they were equal
                c--;
             //if not equal before & after updation then continue
        }
        
        return c == 26;
    }
};
