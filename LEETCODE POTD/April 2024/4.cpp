/*
Difficulty: Easy
Problem Name: 1614. Maximum Nesting Depth of the Parentheses
Problem Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/?envType=daily-question&envId=2024-04-04
Concepts Used: Stack, String, Implementation
Note: Whenever you see a problem with parentheses, think of using a stack💡
*/

#include <bits/stdc++.h>
using namespace std;

/*
Approach1: We can use a stack to keep track of the parentheses
TC: O(n) n is the size of the string
SC: O(n) n is the size of the string
*/
class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        stack<char> stk;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                stk.push(s[i]);
                int stk_size = stk.size(); //size of the stack is the depth of the parentheses
                ans = max(ans,stk_size);
            }
            else if(s[i]==')'){
                stk.pop();
            }
        }

        return ans;
    }
};

/*
Approach2: Instead of using a stack, we can use a variable to keep track of the number of open brackets
TC: O(n) n is the size of the string
SC: O(1)
*/
class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        stack<char> stk;
        int ans = 0;
        int open_bracket = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                open_bracket++; //open bracket will tell us the depth of the parentheses
                ans = max(ans,open_bracket);
            }
            else if(s[i]==')') open_bracket--;
        }

        return ans;
    }
};