/*
Difficulty: Easy
Problem Name: 58. Length of Last Word
Problem Link: https://leetcode.com/problems/length-of-last-word/description/?envType=daily-question&envId=2024-04-01
Concepts Used: Strings
TC:  O(n) traversing the array once
SC: O(1) using no extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' ' && count==0)continue;
            if(s[i]==' ' && count!=0)return count;
            if(s[i]!=' ')count++;
        }
        return count;
    }
};