//
//  a825FriendsOfAppropriateAges.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/31/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    
    int numFriendRequests(vector<int>& ages) {
        
        vector<int> count(121, 0);
        for (int age: ages) count[age]++;

        int ans = 0;
        for (int ageA = 0; ageA <= 120; ageA++) {
            int countA = count[ageA];
            for (int ageB = 0; ageB <= 120; ageB++) {
                int countB = count[ageB];
                if (ageA * 0.5 + 7 >= ageB) continue;
                if (ageA < ageB) continue;
                if (ageA < 100 && 100 < ageB) continue;
                ans += countA * countB;
                if (ageA == ageB) ans -= countA;
            }
        }

        return ans;
    }
    
    // More generic when ages can be arbitary integer
    /*
    int numFriendRequests(vector<int>& ages) {
        
        sort(ages.begin(), ages.end());

        int count = 0;
        
        auto Ait = ages.begin();
        auto Aprev = ages.begin();
        auto Apost = ages.begin();
        
        while( Ait != ages.end()) {
            while(Aprev != ages.end() && *Ait * 0.5 + 7 >= *Aprev) {
                Aprev++;
            }
            
            while(Apost != ages.end() && *Apost == *Ait) {
               Apost++;
            }
            
            if (Aprev < Apost) {
                count += (int)(prev(Apost) - Aprev);
                cout << "A: " << *Ait << " count: " << count << endl;
                cout << "Aprev: " << *Aprev << " Apost-1: " << *prev(Apost) << endl;
            }
            Ait++;
        }
        
        return count;
    }
     */
};

/*
int main() {
    // 56 -> 48
    // 69 -> 48
    // 69 -> 56
    //
    vector<int> ages = {73,106,39,6,26,15,30,100,71,35,46,112,6,60,110};
    Solution sol;
    cout << "friends requests: " << sol.numFriendRequests(ages) << endl;
    
    
}
 */
