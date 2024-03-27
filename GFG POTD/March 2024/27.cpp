/*
Difficulty: Medium
Problem Name: Find shortest safe route in a matrix
Problem Link: https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1
Concepts Used: Multi-source BFS, BFS on grid, Shortest Path
TC: O(rows*cols) where rows and cols are the number of rows and columns in the matrix
SC: O(rows*cols) for the visited array
*/

#include<bits/stdc++.h>
using namespace std;

//User function Template for C++

class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       
       int rows = mat.size();
       int cols = mat[0].size();
       
       //directions array
       int dr[] = {-1,0,1,0};
       int dc[] = {0,1,0,-1};
       
       vector<vector<bool>> vis(rows,vector<bool>(cols,false));
       
       //traversing over the grid and if a cell is 0 and not visited,
       // then we make all the adjacent 1s to it equal to 0
       for(int i=0; i<rows; i++){
           for(int j=0; j<cols; j++){
               if(mat[i][j]==0 && !vis[i][j]){
                   //going on all the adjacent cells
                   for(int k=0; k<4; k++){
                       int nr = i+dr[k];
                       int nc = j+dc[k];
                       
                       if(nr>=0 && nr<rows && nc>=0 && nc<cols && mat[nr][nc]==1 && !vis[nr][nc]){
                           mat[nr][nc]=0;
                           vis[nr][nc]=true;
                       }
                   }
               }
           }
       }
       
       
       for(int i=0; i<rows; i++){
           for(int j=0; j<cols; j++){
               vis[i][j]=false;
           }
       }

       queue<pair<pair<int,int>,int>> q;
       //pushing all the cells having 1 in the first column to the queue, 
       // as they can be the starting points of the path
       for(int i=0; i<rows; i++){
           if(mat[i][0]==1){
               q.push({{i,0},1});
               vis[i][0]=true;
           }
       }
       
       //Multi-source BFS
       while(!q.empty()){
           int curr_row = q.front().first.first;
           int curr_col = q.front().first.second;
           int path_length = q.front().second;
           q.pop();
           
           //if we reach the last column, then we return the path length,
           // because this is the shortest path
           if(curr_col==cols-1){
               return path_length;
           }
           
           //going on all the adjacent cells
           for(int i=0; i<4; i++){
               int nr = curr_row+dr[i];
               int nc = curr_col+dc[i];
               
               if(nr>=0 && nr<rows && nc>=0 && nc<cols && mat[nr][nc]==1 && !vis[nr][nc]){
                   q.push({{nr,nc},path_length+1});
                   vis[nr][nc]=true;
               }
           }
       }
       
       //if we reach here, then there is no path from the first column to the last column
       return -1;
       
    }
};