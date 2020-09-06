//
//  a1025DivisorGame.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/6/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    bool divisorGame(int N) {
        /*Optimal way to win this game is to stay on even numbers. When a player has to make a move if its odd number, no matter what he does he will end up converting into a even number. If its a even number player has the comfort of converting it into a odd number by substracting 1 to make it odd (N%1==0). On his next turn he will get the even number again. */
        return N % 2 == 0;
    }
};
