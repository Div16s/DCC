/*
Difficulty: Medium
Problem Name: 713. Subarray Product Less Than K
Problem Link: https://leetcode.com/problems/subarray-product-less-than-k/description/?envType=daily-question&envId=2024-03-27
Concepts Used: Sliding Window, Two Pointers, Counting subarrays
TC:  O(n) traversing the array once
SC: O(1) using no extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int curr_product=1;
        int i=0,j=0; //two pointers
        //sliding window
        while(j<nums.size()){
            curr_product = curr_product*nums[j];
            //if the product is greater than k, then we divide the product by the element at i
            // as we are shrinking the current window from left
            while(curr_product>=k && i<nums.size()){
                curr_product/=nums[i];
                i++;
            }
            
            //if the product is less than k, then we add the number of subarrays that can be formed
            // all the subarrays starting from [i,j] and ending at j will be counted
            if(curr_product<k){
                ans+=(j-i+1);
            }

            //increment the right pointer, expanding the current window
            j++;
        }

        return ans;
    }
};