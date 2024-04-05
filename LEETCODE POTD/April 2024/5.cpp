/*
Difficulty: Easy
Problem Name: 1544. Make The String Great
Problem Link: https://leetcode.com/problems/make-the-string-great/description/?envType=daily-question&envId=2024-04-05
Concepts Used: Strings, Stack, ASCII Values
TC:  O(n) traversing the array once
SC: O(n) using stack
*/

//ASCII values of lowercase and uppercase alphabets differ by 32
//ASCII values of lowercase alphabets are from 97 to 122
//ASCII values of uppercase alphabets are from 65 to 90

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        stack<char> stk;
        string good = "";
        for(int i=0; i<n; i++){
            if(stk.empty()){
                stk.push(s[i]);
            }
            else if((stk.top()+32 == s[i]+0) || (stk.top()+0 == s[i]+32)){
                    stk.pop();
            }
            else stk.push(s[i]);  
        }

        while(!stk.empty()){
            good = stk.top() + good;
            stk.pop();
        }

        return good; 
    }
};