//
//  FindLaddersII.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 14/12/7.
//  Copyright (c) 2014年 Jingtao Ren. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class FindLaddersII {
public:
    unordered_map<string,vector<string> > mp; // result map
    vector<vector<string> > res;
    vector<string> path;
    
    void findDict2(string str, unordered_set<string> &dict,unordered_set<string> &next_lev){
        int sz = str.size();
        string s = str;
        for (int i=0;i<sz;i++){
            s = str;
            for (char j = 'a'; j<='z'; j++){
                s[i]=j;
                if (dict.find(s)!=dict.end()){
                    next_lev.insert(s);
                    mp[s].push_back(str);
                }
            }
        }
    }
    
    void output(string &start,string last){
        if (last==start){
            reverse(path.begin(),path.end());
            res.push_back(path);
            reverse(path.begin(),path.end());
        }else{
            for (int i=0;i<mp[last].size();i++){
                path.push_back(mp[last][i]);
                output(start,mp[last][i]);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        mp.clear();
        res.clear();
        path.clear();
        
        dict.insert(start);
        dict.insert(end);
        
        unordered_set<string> cur_lev;
        cur_lev.insert(start);
        unordered_set<string> next_lev;
        path.push_back(end);
        
        
        while (true){
            for (auto it = cur_lev.begin();it!=cur_lev.end();it++){dict.erase(*it);} //delete previous level words
            
            for (auto it = cur_lev.begin();it!=cur_lev.end();it++){  //find current level words
                findDict2(*it,dict,next_lev);
            }
            
            if (next_lev.empty()){return res;}
            
            if (next_lev.find(end)!=dict.end()){ //if find end string
                output(start,end);
                return res;
            }
            
            cur_lev.clear();
            cur_lev = next_lev;
            next_lev.clear();
        }
        return res;
    }
    /*
     * My solution, not pass, need to understand the difference much deeper
     *
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>>  prev;
        vector<string> ini;
        ini.push_back(start);
        prev.push_back(ini);
        unordered_map<string, unordered_set<string>> tMap;
        
        if(start == end)
        {
            return prev;
        }
        return findLadders(prev, end, dict, tMap);
        
    }
    
    vector<vector<string>> findLadders(vector<vector<string>> prev, string end, unordered_set<string> &dict, unordered_map<string, unordered_set<string>>& tMap) {
        vector<vector<string>> ret;
        vector<vector<string>> currentPrev;
        for (auto iter1 = prev.begin(); iter1!= prev.end(); ++iter1) {
            unordered_map<string, unordered_set<string>>::iterator iter2;
            string& theLast = (*iter1)[iter1->size() -1];
            cout << "The Last string : "<< theLast<<endl;
            iter2 = tMap.find(theLast);
            
            if(iter2 == tMap.end())
            {
                unordered_set<string> candiates;
                if(findOneDistanceInDict(theLast, dict, candiates))
                {
                    cout<<"4"<<endl;
                    if(candiates.find(end)!= candiates.end())
                    {
                        vector<string> temp;
                        temp.insert(temp.begin(), iter1->begin(), iter1->end());
                        temp.push_back(end);
                        ret.push_back(temp);
                    }
                    else
                    {
                        if(ret.size()==0)
                        {
                            cout<< "Candiates size: "<<candiates.size()<<endl;
                            for(auto iter3 = candiates.begin(); iter3!= candiates.end(); iter3++)
                            {
                                vector<string> temp;
                                temp.insert(temp.begin(), iter1->begin(), iter1->end());
                                temp.push_back(*iter3);
                                currentPrev.push_back(temp);
                                cout<<"3"<<endl;
                                
                            }
                        }
                    }
                    
                    //tMap.insert(make_pair(theLast, candiates));
                    
                }
            }
            else
            {
                unordered_set<string>& candiates = iter2->second;
                if(candiates.find(end)!= candiates.end())
                {
                    vector<string> temp;
                    temp.insert(temp.begin(), iter1->begin(), iter1->end());
                    temp.push_back(end);
                    ret.push_back(temp);
                }
                else
                {
                    if(ret.size()==0)
                    {
                        for(auto iter3 = candiates.begin(); iter3!= candiates.end(); iter3++)
                        {
                            vector<string> temp;
                            temp.insert(temp.begin(), iter1->begin(), iter1->end());
                            temp.push_back(*iter3);
                            currentPrev.push_back(temp);
                            
                        }
                    }
                }
            }
        }
        
        if(ret.size() != 0 )
        {
            cout<<"1"<<endl;
            return ret;
        }
        
        if(currentPrev.size() == 0)
        {
            cout<<"2"<<endl;
            return ret;
        }
        
        return findLadders(currentPrev, end, dict, tMap);
    }
    
    bool findOneDistanceInDict(string origin, unordered_set<string> &dict, unordered_set<string> &output)
    {
        
        size_t len = origin.length();
        char* temp = new char[len + 1];
        memcpy(temp, origin.c_str(), len);
        temp[len] = '\0';
        
        for (int i =0 ; i< len; i++) {
            cout<<"iter :"<<i<<endl;
            char c = temp[i];
            for (int j = 0; j < 26; j++) {
                if('a' + j == c)
                {
                    continue;
                }
                
                temp[i] = 'a' + j;
                string str = string(temp);
                cout<<"Check str: "<<str<<endl;
                if(dict.find(str) != dict.end())
                {
                    output.insert(str);
                    cout<<"find str: "<<str<<endl;
                }
                temp[i] = c;
            }
        }
        
        if( output.size()!= 0 )
        {
            return true;
        }
        cout<<"Return false for candidates" <<endl;
        return false;
        
    }
     */
};