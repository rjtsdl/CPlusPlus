//
//  SmallerNearestStockDate.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/4/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

vector<int> predictAnswer(vector<int> stockData, vector<int> queries) {
    // preIndex store the nearest smaller index before the current index
    // pre store the incremental indexes based on stock price.
    // because, no need to have a i< j and stockData[i] > stockData[j]
    // because there is impossible to pick i later on, j is better in every aspect
    // 1. stockData[j] is smaller
    // 2. j is closer
    stack<int> pre;
    vector<int> preIndex(stockData.size(), -1);
    for (int i =0; i < stockData.size(); i++) {
        while (!pre.empty() && stockData[i] <= stockData[pre.top()]) {
            pre.pop();
        }
        if (!pre.empty()) {
            preIndex[i] = pre.top();
        }
        pre.push(i);
    }
    
    // post shared the same idea, but it is storing the nearest smaller index after index i
    stack<int> post;
    vector<int> postIndex(stockData.size(), -1);
    for (int i =stockData.size()-1; i >= 0; i--) {
        while (!post.empty() && stockData[i] <= stockData[post.top()]) {
            post.pop();
        }
        
        if (!post.empty()) {
            postIndex[i] = post.top();
        }
        post.push(i);
    }
    
    // I could have used the same stack instead of two (pre and post). This is for better readability
    // During processing of postIndex, we could have to just place the index closest no matter it is pre or post. This way, we can save the logic of those if else in the query place. Again for better readability, I am not implementing like that.
    
    // using pre and post index table to find the nearest smaller stock index
    // because the constance runtime for each query, this can be very scalable
    // Note need to correct index by 1 to be 1-indexed date
    vector<int> output;
    for (int q : queries) {
        if (preIndex[q-1] == -1 && postIndex[q-1] == -1) output.push_back(-1);
        else if (postIndex[q-1] == -1) output.push_back(preIndex[q-1]+1);
        else if (preIndex[q-1] == -1) output.push_back(postIndex[q-1]+1);
        else {
            int pr = preIndex[q-1];
            int ps = postIndex[q-1];
            if (q-1-pr > ps -q+1) {
                output.push_back(postIndex[q-1]+1);
            } else {
                output.push_back(preIndex[q-1]+1);
            }
        }
    }
    return output;
}
