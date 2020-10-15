//
//  a676ImplementMagicDictionary.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/15/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_set>

using namespace std;

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    unordered_set<string> st;
    MagicDictionary() {
        st.clear();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto s:dictionary)
        {
            st.insert(s);
        }
    }
    bool search(string word) {
        
        int n=word.length();
        string t=word;
        for(int i=0;i<n;i++)
        {
            t=word;
            for(int j=0;j<26;j++)
            {
                t[i]=j+'a';
                if(st.count(t) && t!=word)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
