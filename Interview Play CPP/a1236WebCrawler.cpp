//
//  a1236WebCrawler.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/24/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <set>
#include <queue>

using namespace std;

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    class HtmlParser {
      public:
        vector<string> getUrls(string url);
    };
    
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        set<string> explored;
        queue<string> toExplore;
        string hostName = getHostName(startUrl);
        
        toExplore.push(startUrl);
        
        while (!toExplore.empty()) {
            string url = toExplore.front();
            toExplore.pop();
            
            if (explored.count(url) != 0) continue;
            
            explored.insert(url);
            
            vector<string> fanOut = htmlParser.getUrls(url);
            for(string& u: fanOut) {
                if (explored.count(u) != 0 || getHostName(u) != hostName) {
                    continue;
                }
                
                toExplore.push(u);
            }
        }
        
        vector<string> res;
        res.insert(res.end(), explored.begin(), explored.end());
        
        return res;
    }
    
    string getHostName(string url) {
        return url.substr(0,url.find('/',7));
    }
};
