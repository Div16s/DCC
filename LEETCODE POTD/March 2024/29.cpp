/*
Difficulty: Medium
Problem Name: 2962. Count Subarrays Where Max Element Appears at Least K Times
Problem Link: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2024-03-29
Concepts Used: Sliding Window, Two Pointers, Hashing
TC:  O(n) traversing the array once
SC: O(1) using no extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxe = *max_element(nums.begin(), nums.end());
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==maxe) count++;
        }
        if(count<k) return 0;
        long long ans=0;
        int i=0,j=0;
        unordered_map<int,int> mp;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp[maxe]>=k){
                while(mp[maxe]>=k && i<=j){
                    ans+=(1+(nums.size()-1-j));
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]);
                    i++;
                }
            }
            j++;
        }
        
        return ans;
    }
};