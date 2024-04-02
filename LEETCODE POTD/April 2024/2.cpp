/*
Difficulty: Easy
Problem Name: 205. Isomorphic Strings
Problem Link: https://leetcode.com/problems/isomorphic-strings/description/?envType=daily-question&envId=2024-04-02
Concepts Used: Strings
TC:  O(n) traversing the array once
SC: O(256) as there are 256 characters in ASCII
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
         int n = s.size();
         int m = t.size();
         if(n!=m) return false; //if the lengths are not equal, then the strings cannot be isomorphic
        
        map<char,char> smp;
        map<char,char> tmp;
        for(int i=0; i<n; i++){
            if(!smp[s[i]] && !tmp[t[i]]){ //if the characters are not mapped, then map them
                smp[s[i]]=t[i];
                tmp[t[i]]=s[i];
            }
            else if(smp[s[i]]==t[i] && tmp[t[i]]==s[i]){ //if the characters are already mapped, then continue
                continue;
            }
            else{  //if the characters are not mapped correctly, then return false
                return false;
            }
        }
        return true;
    }
};