//
//  a901OnlineStockSpan.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/25/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class StockSpanner {
private:
    vector<vector<int>> m_span;
public:
    
    StockSpanner() : m_span(0) {
        
    };
    
    int next(int price) {
        int s = 1;
        int n = m_span.size();
        while (n > 0 && m_span[n-1][0] <= price) {
            s += m_span[n-1][1];
            n -= m_span[n-1][1];
        }
        m_span.push_back({price, s});
        return m_span.back()[1];
    }
};

/*
 // Use stack
 class StockSpanner {
     Stack<Integer> prices, weights;

     public StockSpanner() {
         prices = new Stack();
         weights = new Stack();
     }

     public int next(int price) {
         int w = 1;
         while (!prices.isEmpty() && prices.peek() <= price) {
             prices.pop();
             w += weights.pop();
         }

         prices.push(price);
         weights.push(w);
         return w;
     }
 }
 */

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
