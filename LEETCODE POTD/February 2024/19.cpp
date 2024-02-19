/*
Difficulty: Easy
Problem Name: 231. Power of Two
Problem Link: https://leetcode.com/problems/power-of-two/description/?envType=daily-question&envId=2024-02-19
Concepts Used: BitManipulation
TC: O(1) 
SC: O(1) 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return ((n&(n-1))==0);
    }
};