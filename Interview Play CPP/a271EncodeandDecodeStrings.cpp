//
//  a271EncodeandDecodeStrings.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/13/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Codec {
public:
    
    string encode(vector<string>& strs, string encoded = "") {
        for (string &s : strs) encoded += to_string(s.size()) + '.' + s;
        return encoded;
    }

    vector<string> decode(string s, vector<string> decoded = {}) {
        for (int i = 0, n = 0; i < s.size(); i += n, n = 0) {
            while (isdigit(s[i])) n = 10 * n + (s[i++] - '0');
            decoded.push_back(s.substr(++i, n));
        }
        return decoded;
    }
};
