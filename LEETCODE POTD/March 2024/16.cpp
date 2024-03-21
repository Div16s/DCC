/*
Difficulty: Medium
Problem Name: 525. Contiguous Array
Problem Link: https://leetcode.com/problems/contiguous-array/description/?envType=daily-question&envId=2024-03-16
Concepts Used: Hashing, Prefix Sum
TC: O(n) traversing the array once 
SC: O(n) using a map to store the prefix sum and its index

SIMILAR PATTERN QUESTIONS: LeetCode 560. Subarray Sum Equals K, LeetCode 523. Continuous Subarray Sum
                           LeetCode 930. Binary Subarrays With Sum, LeetCode 325. Maximum Size Subarray Sum Equals k
                           LeetCode 1074. Number of Submatrices That Sum to Target, LeetCode 1248. Count Number of Nice Subarrays
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        //replacing 0s with -1s
        for(int i=0; i<n; i++){
            if(nums[i]==0) nums[i]=-1;
        }

        //map to store the prefix sum and its index
        map<int,int> mp;
        int curr_sum = 0;
        mp[0]=-1; //initially the 0 sum is seen at index -1
        int ans = 0;
        for(int i=0; i<n; i++){
            curr_sum+=nums[i];
            //if the current sum is already seen before
            if(mp.find(curr_sum)!=mp.end()){
                int len = i-mp[curr_sum]; //length of the subarray with equal number of 0s and 1s or sum==0
                ans = max(ans,len);
            }
            else mp[curr_sum]=i; //store the current sum and its index
        }

        return ans;
    }
};