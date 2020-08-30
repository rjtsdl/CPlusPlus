//
//  a635DesignLogStorageSystem.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

class LogSystem {
public:
    map<string,int> save;
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        save[timestamp] = id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        string news = "";
        string newe = "";
        if(gra == "Year"){
            news = s.substr(0,4) + ":00:00:00:00:00";
            newe = e.substr(0,4) + ":99:99:99:99:99";
        }
        else if(gra == "Month"){
            news = s.substr(0,7) + ":00:00:00:00";
            newe = e.substr(0,7) + ":99:99:99:99";
        }
        else if(gra == "Day"){
            news = s.substr(0,10) + ":00:00:00";
            newe = e.substr(0,10) + ":99:99:99";
        }
        else if(gra == "Hour"){
            news = s.substr(0,13) + ":00:00";
            newe = e.substr(0,13) + ":99:99";
        }
        else if(gra == "Minute"){
            news = s.substr(0,16) + ":00";
            newe = e.substr(0,16) + ":99";
        }
        else{
            news = s;
            newe = e;
        }
        
        auto iters = save.find(news);
        auto itere = save.find(newe);
        if(iters == save.end())save[news] = -1;
        if(itere == save.end())save[newe] = -1;
        iters = save.find(news);
        itere = save.find(newe);
        vector<int> ret;
        for(auto iter=iters; iter!=itere; iter++){
            if(iter->second != -1)ret.push_back(iter->second);
        }
        if(itere->second != -1)ret.push_back(itere->second);
        if(iters->second == -1)save.erase(iters);
        if(iters != itere && itere->second == -1)save.erase(itere);
        return ret;
        
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(s,e,gra);
 */
