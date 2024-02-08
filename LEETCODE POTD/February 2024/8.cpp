/*
Difficulty: Medium
Problem Name: 279. Perfect Squares
Problem Link: https://leetcode.com/problems/perfect-squares/description/?envType=daily-question&envId=2024-02-08
Concepts Used: Perfect Square & Recursion+DP
TC: O(n*s)
SC: O(n*s)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCoinsToGetS(vector<int>& coins, int n, int S, vector<vector<int>>& dp) {
        //base cases
        if(n == 0)
            return 1e9;
        if(S == 0)
            return 0;
        if(n == 1) {
            if(S % coins[0] == 0)
                return dp[n][S] = S/coins[0];
            else
                return dp[n][S] = 1e9;
        }

        if(dp[n][S] != -1)
            return dp[n][S];
        
        if(coins[n-1] <= S) {
            return dp[n][S] = min(1 + minCoinsToGetS(coins, n, S-coins[n-1], dp), minCoinsToGetS(coins, n-1, S, dp));
        } else
            return dp[n][S] = minCoinsToGetS(coins, n-1, S, dp);
    }
    int numSquares(int S) {
        vector<int> coins;
        for(int i = 1; i*i<=S; i++) {
            coins.push_back(i*i);
        }
        int n = coins.size();
        
        vector<vector<int>> dp(n+1, vector<int>(S+1, -1));
        return minCoinsToGetS(coins, n, S, dp);
    }
};