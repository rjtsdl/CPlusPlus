//
//  a359LoggerRateLimiter.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/27/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <string>

using namespace std;

class Logger {
public:
    unordered_map<string, int> m_previousTimeStamp;
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (m_previousTimeStamp.find(message) == m_previousTimeStamp.end() ||
            m_previousTimeStamp[message] <= timestamp - 10) {
            m_previousTimeStamp[message] = timestamp;
            return true;
        }
        return false;
        
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
