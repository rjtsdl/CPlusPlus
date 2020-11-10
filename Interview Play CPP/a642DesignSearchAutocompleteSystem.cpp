//
//  a642DesignSearchAutocompleteSystem.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/10/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class TrieNode {
public:
    vector<TrieNode*> m_children;
    map<string, int> m_top3;
    
    TrieNode() {
        m_children = vector<TrieNode*>(256, nullptr);
    }
    
    void insert(const string& s, int i, int c) {
        mergeString(s, c);
        if (i < s.size()) {
            if (m_children[s[i]] == nullptr) {
                m_children[s[i]] = new TrieNode();
            }
            m_children[s[i]]->insert(s, i+1, c);
        }
    }
    
    vector<string> genTopS() {
        vector<pair<int, string>> tmp;
        for (auto kv : m_top3) {
            tmp.push_back({kv.second, kv.first});
        }
        
        sort(tmp.begin(), tmp.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        });
        
        vector<string> ret;
        for (auto it = tmp.rbegin(); it!= tmp.rend(); it++) {
            ret.push_back(it->second);
        }
        return ret;
    }
    
    void mergeString(string s, int c) {
        m_top3[s]=c;
        if (m_top3.size() > 3) {
            int minC = c;
            string minS = s;
            
            for (auto kv : m_top3) {
                if (kv.second <= minC) {
                    minC = kv.second;
                    minS = kv.first;
                }
            }
            m_top3.erase(minS);
        }
    }
};


class AutocompleteSystem {
    TrieNode* m_root;
    string m_buffer;
    TrieNode* m_currNode;
    unordered_map<string, int> m_history;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        m_root = new TrieNode();
        int n = sentences.size();
        for (int i =0; i< n; i++) {
            m_root->insert(sentences[i], 0, times[i]);
            m_history[sentences[i]] += times[i];
        }
        m_buffer = "";
        m_currNode = m_root;
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            if (m_buffer.empty()) return {};
            m_history[m_buffer]++;
            m_root->insert(m_buffer, 0, m_history[m_buffer]);
            m_buffer = "";
            m_currNode = m_root;
            
        } else {
            m_buffer += c;
            if (m_currNode != nullptr) {
                m_currNode = m_currNode->m_children[c];
                if (m_currNode != nullptr) return m_currNode->genTopS();
            }
        }
        return {};
        
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
