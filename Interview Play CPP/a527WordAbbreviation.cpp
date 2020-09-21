//
//  a527WordAbbreviation.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/20/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct Trie
{
    Trie() : children(26, shared_ptr<Trie>())
    {
    }
    
    void insert(string& s, int index)
    {
        if (index == s.size())
            return;
        
        if (!children[s[index] - 'a'])
            children[s[index] - 'a'] = make_shared<Trie>();
        
        children[s[index] - 'a']->weight++;
        children[s[index] - 'a']->insert(s, index + 1);
    }
    
    int findUniqueIndex(string& s, int index)
    {
        if (index == s.size() || children[s[index] - 'a']->weight < 2)
            return index;
        
        return children[s[index] - 'a']->findUniqueIndex(s, index + 1);
    }
    
    size_t weight = 0;
    vector<shared_ptr<Trie>> children;
};

class Solution
{
public:
    string getAbbr(string s, int index)
    {
        if (s.size() < 4 || s.size() - index - 2 < 2)
            return s;
        
        if (index == 0)
            return s.front() + to_string(s.size() - 2) + s.back();
        
        return s.substr(0, index + 1) + to_string(s.size() - 2 - index) + s.back();
    }
    
    vector<string> wordsAbbreviation(vector<string>& dict)
    {
        vector<vector<shared_ptr<Trie>>> tries(26,
            vector<shared_ptr<Trie>>(401, shared_ptr<Trie>()));
        
        for (auto word : dict)
        {
            if (!tries[word.back() - 'a'][word.size()])
                tries[word.back() - 'a'][word.size()] = make_shared<Trie>();
            
            tries[word.back() - 'a'][word.size()]->insert(word, 0);
        }
        
        vector<string> result;
        
        for (auto word : dict)
            result.push_back(word.size() < 4 ? word : getAbbr(word,
                tries[word.back() - 'a'][word.size()]->findUniqueIndex(word, 0)));
        
        return result;
    }
};
