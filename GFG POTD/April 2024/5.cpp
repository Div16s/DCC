/*
Difficulty: Hard
Problem Name: Strictly Increasing Array
Problem Link: https://www.geeksforgeeks.org/problems/convert-to-strictly-increasing-array3351/1
Concepts Used: Dynamic Programming, Longest Increasing Subsequence
TC: O(n^2)
SC: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int min_operations(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n,1); //dp[i] stores the length of the longest increasing subsequence ending at index i
        for(int i=1;i<n;i++){ 
            for(int j=0;j<i;j++){
                if(nums[i]>=(nums[j]+(i-j))){ 
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        int max_len=1;
        for(int i=0;i<n;i++){
            max_len=max(max_len,dp[i]);
        }
        
        return (n - max_len); //returning the number of elements to be removed
    }
};