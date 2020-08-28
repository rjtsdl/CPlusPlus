//
//  a1268SearchSuggestionsSystem.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/27/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
     int n=products.size();
     vector<vector<string>>result;
     sort(products.begin(),products.end());
     string temp;bool inserted=true;
     for(char ch:searchWord)
     {
         vector<string>res;
         temp+=ch;
         if(!inserted)
         {
             result.push_back(res);
             continue;
         }
         auto it=lower_bound(products.begin(),products.end(),temp);
         if(it==products.end())
         {
             result.push_back(res);
             inserted=false;
         }
         else
         {
             int pos=it-products.begin();
             for(int i=pos;i<min(pos+3,n);i++)
             {
                 if(products[i].length()>=temp.length()&&products[i].substr(0,temp.length())==temp) res.push_back(products[i]);
                 else break;
             }
             result.push_back(res);
         }
     }
    return result;
    }
};
