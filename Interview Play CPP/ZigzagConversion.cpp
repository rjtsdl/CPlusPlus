//
//  ZigzagConversion.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 10/20/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class ZigzagConversion
{
public:
    string convert(string s, int numRows) {
        
        bool downward = true;
        int pos = 0;
        int row = 0;
        string* tempStrings = new string[numRows];
        for (int i = 0 ; i < numRows ; ++i)
        {
            tempStrings[i] = "";
        }
        
        while (pos < s.size())
        {
            tempStrings[row].push_back(s[pos]);
            pos++;
            if (downward) {
                row++;
            }
            else
            {
                row--;
            }
            
            if (row >= numRows) {
                row = max(numRows-2, 0);
                downward = false;
            }
            else if (row < 0)
            {
                row = min(1, numRows-1);
                downward = true;
            }
        }
        
        string ret = "";
        for (int i = 0 ; i < numRows ; ++i)
        {
            ret += tempStrings[i];
        }
        delete [] tempStrings;
        return ret;
    }
};

/*

int main()
{
    ZigzagConversion obj;
    obj.convert("ABDJ", 3);
}
 */


