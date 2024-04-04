/*
Difficulty: Medium
Problem Name: Sum of all substrings of a number
Problem Link: https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1
Concepts Used: Dynamic Programming, Bottom-up approach, Maths
*/

#include<bits/stdc++.h>
using namespace std;

int MOD = 1000000007;

/*
Bottom-up approach:
TC: O(n) 
SC: O(n) for the dp array
*/
class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // sum[3] = s[3]*(3+1) + (sum[2])*10
        // sum[3] = sum of substrings ending at index 3
        // sum[2] = sum of substrings ending at index 2 
        int n = s.size();
        long long sum = 0;
        vector<long long> dp(n,0);
        dp[0]=(s[0]-'0'); //base case
        for(int i=1; i<n; i++){
            dp[i] = (((s[i]-'0')*(i+1))%MOD + ((dp[i-1])*10)%MOD)%MOD;
        }
        
        for(int i=0; i<n; i++){
            sum = (sum + dp[i]%MOD)%MOD;
        }
        
        return sum%MOD;
    }
};

/*
Bottom-up Space-Optimized approach:
TC: O(n) 
SC: O(1)
*/
class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        int n = s.size();
        long long sum = (s[0]-'0');
        long long prev = (s[0]-'0');
        long long curr = 0;
        for(int i=1; i<n; i++){
            curr = (((s[i]-'0')*(i+1))%MOD + ((prev)*10)%MOD)%MOD;
            sum = (sum + curr)%MOD;
            prev = curr;
        }
        
        return sum;
    }
};