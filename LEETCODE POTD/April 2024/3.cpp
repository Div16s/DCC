/*
Difficulty: Medium
Problem Name: 79. Word Search
Problem Link: https://leetcode.com/problems/word-search/description/?envType=daily-question&envId=2024-04-03
Concepts Used: Backtracking, DFS
TC: O(m*n) m is the number of rows, n is the number of columns
SC: O(m*n)
*/

#include <bits/stdc++.h>
using namespace std;

//directions
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

class Solution {
public:
    //function to check if the given row and column are valid
    bool isValid(int nr, int nc, int m, int n){
        return (nr>=0 && nr<m && nc>=0 && nc<n);
    }

    //function to perform dfs
    bool dfs(int row, int col, int ind, string word, vector<vector<char>>&board,vector<vector<bool>>&vis){
        if(ind==word.size()) return true;
        vis[row][col]=true;
        bool res = false;
        for(int i=0; i<4; i++){
            int nr = row+dr[i];
            int nc = col+dc[i];

            if(isValid(nr,nc,board.size(),board[0].size()) && board[nr][nc]==word[ind] && !vis[nr][nc]){
                res = res | dfs(nr,nc,ind+1,word,board,vis);
            }
        }
        vis[row][col]=false; //backtracking
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int ws = word.size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0]){
                    int ind = 1;
                    vector<vector<bool>> vis(m,vector<bool>(n,false));
                    if(dfs(i,j,ind,word,board,vis)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};