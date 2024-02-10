/*
Difficulty: Medium
Problem Name: 647. Palindromic Substrings
Problem Link: https://leetcode.com/problems/palindromic-substrings/description/?envType=daily-question&envId=2024-02-10
*/

#include<bits/stdc++.h>
using namespace std;


//Concepts Used: DP & Palindrome //
//TC: O(n^2) SC: O(n^2) //
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(i==j){
                    dp[i][j]=1;
                }
                else if(j==i+1){
                    dp[i][j]=(s[i]==s[j])?1:0;
                }
                else{
                    dp[i][j]=(s[i]==s[j])?dp[i+1][j-1]:0;
                }
                ans+=dp[i][j];
            }
        }

        return ans;
    }
};

//Most Optimal Solution //
//Pure Palindrome Concept//
//TC -> O(n^2)  SC -> O(1) //
class Solution {
public:
    void countPalindromes(int i, int j, int n, int &ans, string s){
        while(i>=0 && j<n && s[i]==s[j]){
            ans++;
            i--;
            j++;
        }
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            countPalindromes(i,i,n,ans,s); //odd length palindrome // 1 ele center
            countPalindromes(i,i+1,n,ans,s); //even length palindrome // 2 ele center
        }

        return ans;
    }
};