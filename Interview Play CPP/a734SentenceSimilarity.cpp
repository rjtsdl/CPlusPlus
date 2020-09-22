//
//  a734SentenceSimilarity.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;

        set<string> mySet;
        for (int i = 0; i < pairs.size(); ++i)
            mySet.emplace(pairs[i][0]+"_"+pairs[i][1]);

        for (int i = 0; i < words1.size(); ++i)
            if (!mySet.count(words1[i]+"_"+words2[i]) && !mySet.count(words2[i]+"_"+words1[i]) && words1[i] != words2[i])
                return false;

        return true;
    }
};
