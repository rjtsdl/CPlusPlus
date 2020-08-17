//
//  a465OptimalAccountBalance.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    vector<int> owedArr;
    vector<int> owesArr;
    int transactionsDone = INT_MAX;
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int,int> transMap;
        for(auto each: transactions){
            transMap[each[0]] -= each[2];
            transMap[each[1]] += each[2];
        }
        for(auto each: transMap){
            if(each.second == 0)
                continue;
            if(each.second > 0)
                owesArr.push_back(each.second);
            else
                owedArr.push_back(abs(each.second));
        }
        findMinTransactionsNeeded(0,0);
        return transactionsDone;
    }
    
    void findMinTransactionsNeeded(int owedIndex, int currTransactionDone){
        if(owedIndex == owedArr.size()){
            transactionsDone = min(transactionsDone,currTransactionDone);
            return;
        }
        
        for(int i=0; i<owesArr.size(); ++i){
            if(owesArr[i] == 0)
                continue;
            
            int temp = owesArr[i];
            if(owedArr[owedIndex] <= owesArr[i]){
                /* This transaction gives person at 'index' his money back so move to the next person */
                owesArr[i] -= owedArr[owedIndex];
                findMinTransactionsNeeded(owedIndex+1,currTransactionDone+1);
            }
            else{
                /* This transaction gives person at 'index' partial of this money so continue for him */
                int tempOwed =  owedArr[owedIndex];
                owedArr[owedIndex] -= owesArr[i];
                owesArr[i] = 0;
                findMinTransactionsNeeded(owedIndex,currTransactionDone+1);
                /*backtrack owedArr*/
                owedArr[owedIndex] = tempOwed;
            }
            /* backtrack owesArr*/
            owesArr[i] = temp;
        }
    }
};
