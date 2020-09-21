//
//  a631DesignExcelSumFormula.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Excel {
    unordered_map<string,unordered_map<string,int>> pre,suc;
    unordered_map<string,int> sheet;
    
    vector<string> getcells(string range) {
        if (!range.find('.')) return {range};
        vector<string> res;
        int colon=range.find(':');
        for (int r=stoi(range.substr(1,colon-1));
            r <= stoi(range.substr(colon+2)); r++) {
            for (int c=range[0]-'A'; c <= range[colon+1]-'A'; c++) {
                res.push_back(char(c+'A')+to_string(r));
            }
        }
        return res;
    }
    
    void update(string cell, int val) {
        int delta=val-sheet[cell];
        queue<string> q;
        q.push(cell);
        while (!q.empty()) {
            sheet[q.front()]+=delta;
            for (auto next:suc[q.front()]) {
                for (int i=0; i<next.second; i++){
                    q.push(next.first);
                }
            }
            q.pop();
        }
    }
    
    void clearlinks(string cell) {
        queue<string> q;
        q.push(cell);
        for (auto p:pre[q.front()]) {
            suc[p.first].erase(cell);
        }
        pre[cell].clear();
    }
    
public:
    Excel(int H, char W) { }
    
    void set(int r, char c, int v) {
        string cell = c+to_string(r);
        clearlinks(cell);
        update(cell,v);
    }
    
    int get(int r, char c) {
        return sheet[c+to_string(r)];
    }
    
    int sum(int r, char c, vector<string> strs) {
        string cell = c+to_string(r);
        clearlinks(cell);
        
        for (string v:strs) {
            for (string cur:getcells(v)) {
                pre[cell][cur]++;
                suc[cur][cell]++;
            }
        }
        
        int val=0;
        for (auto m:pre[cell]) {
            val+=sheet[m.first]*m.second;
        }
        update(cell,val);
        return val;
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(H, W);
 * obj->set(r,c,v);
 * int param_2 = obj->get(r,c);
 * int param_3 = obj->sum(r,c,strs);
 */
