/*
Difficulty: Medium
Problem Name: Number of paths in a matrix with k coins
Problem Link: https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1
Concepts Used: DFS, DP, Matrix Based Traversal
TC: O(n*n*k) 3D-DP
SC: O(n*n*k) 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long f(int row, int col, int sum, int n, int k, vector<vector<int>>&matrix,
    vector<vector<vector<long long>>> &dp){
        if(sum>k){
            return 0;
        }
        
        if(row==n-1 && col==n-1){
            if(sum==k) return 1;
            return 0;
        }
        
        if(dp[row][col][sum]!=-1) return dp[row][col][sum];
        
        long long ans = 0;
        if(row+1<n) ans+=f(row+1,col,sum+matrix[row+1][col],n,k,matrix,dp);
        if(col+1<n) ans+=f(row,col+1,sum+matrix[row][col+1],n,k,matrix,dp);
        
        return dp[row][col][sum] = ans;
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        
        // Code Here
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(n,vector<long long>(k+1,-1)));
        return f(0,0,arr[0][0],n,k,arr,dp);
    }
};