//
//  a123BestTimeToBuyAndSellStockIII.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
  int maxProfit(vector<int>& prices) {
    int t1Cost = INT_MAX,
        t2Cost = INT_MAX;
    int t1Profit = 0,
        t2Profit = 0;

    for (int price : prices) {
        // the maximum profit if only one transaction is allowed
        t1Cost = min(t1Cost, price);
        t1Profit = max(t1Profit, price - t1Cost);
        // re-invest the gained profit in the second transaction
        t2Cost = min(t2Cost, price - t1Profit);
        t2Profit = max(t2Profit, price - t2Cost);
        
        cout << "Price: " << price << " t1Cost: " << t1Cost <<" t1Profit: " << t1Profit << " t2Cost: " << t2Cost << "t2Profit: " << t2Profit << endl;
    }

    return t2Profit;
  }
};
/*
int main() {
    vector<int> p{3,3,5,0,0,3,1,4};
    Solution* sol = new Solution();
    sol->maxProfit(p);
    return 0;
    
}
 */
