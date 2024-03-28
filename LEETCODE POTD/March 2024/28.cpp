/*
Difficulty: Medium
Problem Name: 2958. Length of Longest Subarray With at Most K Frequency
Problem Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2024-03-28
Concepts Used: Sliding Window, Two Pointers, Hashing
TC:  O(n) traversing the array once
SC: O(1) using no extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 0;
        //hashmap to store the frequency of elements
        unordered_map<int,int> mp;
        int i=0,j=0;
        //sliding window
        while(j<n){
            mp[nums[j]]++;
            //if the frequency of the element at j exceeds k, then we shrink the window from left
            while(mp[nums[j]]>k && i<=j){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            
            //if the frequency of the element at j is less than or equal to k, then we update the length of the subarray
            len = max(len,j-i+1);
            j++; //expanding the window
        }

        return len;
    }
};