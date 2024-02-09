/*
Difficulty: Medium
Problem Name: 368. Largest Divisible Subset
Problem Link: https://leetcode.com/problems/largest-divisible-subset/description/?envType=daily-question&envId=2024-02-09
Concepts Used: Longest Increasing Subsequence
TC: O(n*n)
SC: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),backtrack(n);
        int max_len=1,lastIndex=0;
        for(int i=0; i<n; i++){
            backtrack[i]=i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    backtrack[i]=j;
                }
            }
            if(dp[i]>max_len){
                max_len=dp[i];
                lastIndex=i;
            }
        }

        vector<int> lds;
        lds.push_back(nums[lastIndex]);
        while(backtrack[lastIndex]!=lastIndex){
            lastIndex = backtrack[lastIndex];
            lds.push_back(nums[lastIndex]);
        }
        reverse(lds.begin(),lds.end());

        return lds;
    }
};