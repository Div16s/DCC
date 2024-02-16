/*
Difficulty: Medium
Problem Name: 1481. Least Number of Unique Integers after K Removals
Problem Link: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/?envType=daily-question&envId=2024-02-16
Concepts Used: HashMap & Priority Queue
TC: O(nlogn) 
SC: O(n) 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Map to track of the frequencies of elements
        unordered_map<int, int> mp;
        for (int i : arr) {
            mp[i]++;
        }

        priority_queue<int,vector<int>,greater<int>> frequencies;
        for(auto it:mp){
            frequencies.push(it.second);
        }

        int elementsRemoved = 0;

        // Traversing all frequencies
        while (!frequencies.empty()) {
            // Removing the least frequent element
            elementsRemoved += frequencies.top();

            // If the number of elements removed exceeds k, return
            // the remaining number of unique elements
            if (elementsRemoved > k) {
                return frequencies.size();
            }
            frequencies.pop();
        }

        return 0;
    }
};