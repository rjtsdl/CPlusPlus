//
//  a1201UglyNumberIII.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/13/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    long __gcd(long a, long b){//calculate gcd of two numbers
        if(b==0){return a;}
        if(a==0){return b;}
        if(b>a){return __gcd(b,a);}
        return __gcd(a%b,b);
    }
    long lcm(int a, int b, int c){//ca;culate lcm of two numbers
        long lcmab = a*b/(__gcd(a,b));
        long lcm = (lcmab*c)/(__gcd(lcmab,c));
        return lcm;
    }
    long fn(long m, int a, int b,int c){//calculate numbers of integers less than equal to m which divisible by any one of [a,b,c]
        long na=m/a,nb=m/b,nc=m/c;//calculate number of integers divisible by a, b and c respectively
        long nab=m/((long)a*(long)b/(__gcd(a,b))),nbc=m/((long)b*(long)c/(__gcd(b,c))),nac=m/((long)c*(long)a/(__gcd(a,c)));//calculate number of integers divisible by both (a, b), (b,c) and (c,a) respectively
        long nabc=m/(lcm(a,b,c));//calculate number of integers divisible by all (a, b, c)
        // n(A U B U C) = n(A + B + C ) - n(A ⋂ B) - n(B ⋂ C) - n(C ⋂ A) + n(A ⋂ B ⋂ C)
        return na+nb+nc-nab-nbc-nac+nabc;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long l=1,r=1000000000000000001;
        while(l<r-1){//binary search over answer range
            long m = l + (r-l)/2;
            if(fn(m,a,b,c)==n){
                if(m%a==0||m%b==0||m%c==0){
                    return m;
                }
                else{r=m;}//if current integers is not divisible by any one of [a,b,c], search continues in lower half of current range
            }
            else if(fn(m,a,b,c)<n){
                l=m;
            }
            else{
                r=m;
            }
        }
        if(fn(r,a,b,c)==n){
            if(r%a==0||r%b==0||r%c==0){return r;}
        }
        r--;
        if(fn(r,a,b,c)==n){
            if(r%a==0||r%b==0||r%c==0){return r;}
        }
        return r-1;
    }
};

int main() {
    Solution* sol = new Solution();
    cout << sol->nthUglyNumber(3,2,3,5);
    return 0;
}
