//
//  InfraConcordance.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'generateAndPrintConcordance' function below.
 *
 * The function accepts STRING_ARRAY inputLines as parameter.
 */

// printResult used to print the final result in the output expected format
void printResult(const map<string, vector<int>>& res) {
    for (auto kv : res) {
        cout << kv.first << ": {" << kv.second.size()<<":";
        for (int i =0; i < kv.second.size(); i++) {
            cout << kv.second[i];
            if (i != kv.second.size()-1) {
                cout << ",";
            }
        }
        cout << "}" << endl;
    }
}

// processLine has the logic in processing a single line
void processLine(int& previousSenNumber, const string& line, map<string, vector<int>>& res, string& token) {
    // used to indicate the current token is an abbreviation
    bool isAbbv = false;
    // used to indicate if there is AEIOUaeiou in the token
    bool hasAEIOU = false;
    int i = 0;
    while (i<line.size()) {
        if (line[i] == ' ' || line[i] == ',' || line[i] == ':') {
            // cases: enough to end the token, but not start a new sentence
            if (!token.empty()) {
                res[token].push_back(previousSenNumber);
            }
            token = "";
            hasAEIOU = false;
            isAbbv = false;
        } else if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) {
            // cases: to extend the token with alphabetical letter
            char c = ::tolower(line[i]);
            token += c;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') hasAEIOU = true;
        } else if (line[i] == '?' || line[i] == '!') {
            // cases: simply just ended token, and start a new sentence
            if (!token.empty()) {
                res[token].push_back(previousSenNumber);
            }
            token = "";
            hasAEIOU = false;
            isAbbv = false;
            previousSenNumber++;
        }else if (line[i] == '.') {
            // this is the most complicated case
            // . could part of an abbreviation or end of a sentence
            if (!isAbbv) {
                // layout the case we can turn this token into a abbreviation case
                // 1. we classify the case if a word without aeiou as abbv, when it has . used together. for example, "Mr.", "Mrs."
                // 2. we classify the case if . after a single letter, it is an abbv. for example "e.g.", "i.e."
                // 3. there could be other case we need to special handling in here, but not currently come up to me. But making the abbreviation case handled here is pretty extensible.
                if (!token.empty() && !hasAEIOU) isAbbv = true;
                else if (token.size() == 1) isAbbv = true;
            }
            if (isAbbv) {
                // if abbreviation, we just extend the token
                token += line[i];
            } else {
                // end of a sentence. The same as ? or !
                if (!token.empty()) {
                    res[token].push_back(previousSenNumber);
                }
                token = "";
                hasAEIOU = false;
                isAbbv = false;
                previousSenNumber++;
            }
        }

        i++;
    }
    if (!token.empty()) {
        // this is the case, the previous sentence end without a ending ? or .
        res[token].push_back(previousSenNumber);
        token = "";
    }

    
}

void generateAndPrintConcordance(vector<string> inputLines) {
    map<string, vector<int>> res;
    int previousSenNumber = 1;
    string token = "";
    for (string& s : inputLines) {
        processLine(previousSenNumber, s, res, token);
    }
    printResult(res);
}

int main()
{
    string inputLines_count_temp;
    getline(cin, inputLines_count_temp);

    int inputLines_count = stoi(ltrim(rtrim(inputLines_count_temp)));

    vector<string> inputLines(inputLines_count);

    for (int i = 0; i < inputLines_count; i++) {
        string inputLines_item;
        getline(cin, inputLines_item);

        inputLines[i] = inputLines_item;
    }

    generateAndPrintConcordance(inputLines);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

