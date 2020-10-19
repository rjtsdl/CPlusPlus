//
//  a884UncommonWordsfromTwoSentences.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> result;
        
        unordered_map<string, int> commonWords;
        
        stringstream s(A); // Used for breaking words
        string word; // to store individual words
  
        while (s >> word)
        {
            commonWords[word]++;
        }
        
        stringstream S(B);
        string wordB;
        
        while(S >> wordB)
        {
            commonWords[wordB]++;
        }
        for(auto i : commonWords)
        {
            if(i.second == 1)
                result.push_back(i.first);
        }
        return result;
    }
};
