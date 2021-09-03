//
//  WildcardMatching.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 14/12/9.
//  Copyright (c) 2014年 Jingtao Ren. All rights reserved.
//

#include <iostream>

using namespace std;

class WildcardMatching {
public:
    /* DP solution
    bool isMatch(const char *s, const char *p) {
        uint lens = 0;
        const char* iter = s;
        while (*iter!= '\0') {
            lens ++;
            iter++;
        }
        if(s[lens] != '\0')
        {
            return false;
        }
        
        uint lenp = 0;
        iter = p;
        while (*iter!='\0') {
            lenp++;
            iter++;
        }
        
        if(p[lenp] != '\0')
        {
            return false;
        }
        
        
        
        bool* dp[2];
        dp[0] = new bool[lens+1];
        dp[1] = new bool[lens+1];
        
        int pOffset = lenp;
        
        for(int i = lenp ; i>=0 ; i--)
        {
            for(int j = lens; j >= 0; j--)
            {
                dp[i-pOffset][j] = false;
                if(p[i] == '\0')
                {
                    if(s[j] == '\0')
                    {
                        dp[i-pOffset][j] = true;
                    }
                }
                else if(p[i] == '*')
                {
                    if(dp[i-pOffset+1][j])
                    {
                        dp[i-pOffset][j] = true;
                    }
                    else if(s[j] != '\0' && dp[i-pOffset][j+1])
                    {
                        dp[i-pOffset][j] = true;
                    }
                }
                else if(p[i] == '?')
                {
                    if(s[j] != '\0' && dp[i-pOffset+1][j+1])
                    {
                        dp[i-pOffset][j] = true;
                    }
                }
                else
                {
                    if(s[j] != '\0' && s[j] == p[i] && dp[i-pOffset+1][j+1])
                    {
                        dp[i-pOffset][j] = true;
                    }
                }
            }
            pOffset --;
            memcpy(dp[1], dp[0], lens+1);
        }
        
        
        return dp[1][0];
        
    }
     */
    
    /* Recursive solution */
    bool isMatch(const char *s, const char *p) {
        if(*p == '\0'&&*s == '\0')
        {
            return true;
        }
        else if (*p == *s || (*p == '?' && *s!='\0'))
        {
            if(isMatch(s+1 , p+1))
            {
                return true;
            }
        }
        else if(*p == '*')
        {   int offset = 1;
            while (*(p + offset) == '*') {
                offset ++ ;
            }
            // point to the last *
            offset--;
            
            if(isMatch(s, p+offset+1))
            {
                return true;
            }
            
            if(*s != '\0' && isMatch(s+1, p+offset))
            {
                return true;
            }
        }
        else{
            return false;
        }
        
        return false;
        
    }
    
    // greedy solution with idea of DFS
    // starj stores the position of last * in p
    // last_match stores the position of the previous matched char in s after a *
    // e.g.
    // s: a c d s c d
    // p: * c d
    // after the first match of the *, starj = 0 and last_match = 1
    // when we come to i = 3 and j = 3, we know that the previous match of * is actually wrong,
    // (the first branch of DFS we take is wrong)
    // then it resets j = starj + 1
    // since we already know i = last_match will give us the wrong answer
    // so this time i = last_match+1 and we try to find a longer match of *
    // then after another match we have starj = 0 and last_match = 4, which is the right solution
    // since we don't know where the right match for * ends, we need to take a guess (one branch in DFS),
    // and store the information(starj and last_match) so we can always backup to the last correct place and take another guess.

     bool isMatch(string s, string p) {
            int i = 0, j = 0;
            int m = s.length(), n = p.length();
            int last_match = -1, starj = -1;
            while (i < m){
                if (j < n && (s[i] == p[j] || p[j] == '?')){
                    i++; j++;
                }
                else if (j < n && p[j] == '*'){
                    starj = j;
                    j++;
                    last_match = i;
                }
                else if (starj != -1){
                    j = starj + 1;
                    last_match++;
                    i = last_match;
                }
                else return false;
            }
            while (p[j] == '*' && j <n) j++;
            return j == n;
        }
    
    /* Solution passed the test, need to figure out the difference with my recursive one
     bool isMatch(const char *s, const char *p) {
     if (!*p && !*s) return true; // both empty, so sad but true
     if (*p == *s) return isMatch(s + 1, p + 1); // match!
     else if (*p == '?' && *s) return isMatch(s + 1, p + 1); // weird match!
     else if (*p == '*') {
     int ret = false;
     while (*p == '*') ++p; // I only need just one starlet ;)
     if (!*p) return true; // ends with star, the Universe can fit into it now!
     while (*s) { // brute force match
     const char *ts = s, *tp = p;
     while ((*ts == *tp || *tp == '?') && *ts) {
     if (*tp == '*') break;
     ++ts; ++tp;
     }
     if (!*ts && !*tp) return true; // both empty
     // *tp is * then ok, otherwise no exact match :(
     if (*tp == '*') {
     // we don't need to concern ourself with more exact matches as the * would take care of it,
     // and for rest brute force matching will be done
     ret |= isMatch(ts, tp);
     return ret;
     }
     if (!*ts) return false; // search exhausted yo! p has more than s can handle :O
     ++s;
     }
     return ret;
     } else return false; // WAT
     }
     */
    
};

/*

int main(int argc, const char * argv[]) {
    
    WildcardMatching wcm;
    if(wcm.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaab", "a*******b"))
    {
        std::cout<<"true"<<std::endl;
    }
    else
    {
        std::cout<<"false"<<std::endl;
    }
}
 */
