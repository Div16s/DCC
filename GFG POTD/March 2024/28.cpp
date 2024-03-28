/*
Difficulty: Medium
Problem Name: City With the Smallest Number of Neighbors at a Threshold Distance
Problem Link: https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1
Concepts Used: Floyd Warshall, Graphs, Shortest Path
TC: O(n^3) where n is the number of cities
SC: O(n^2) for the adjacency matrix
*/

#include<bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        //adjacency matrix
        vector<vector<int>> adj(n,vector<int>(n,1e9));
        //initializing the adjacency matrix
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) adj[i][j]=0; //distance from a city to itself is 0
            }
        }
        //filling the adjacency matrix with the edge weights
        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int ewt = edges[i][2];
            
            adj[u][v]=ewt;
            adj[v][u]=ewt;
        }
        
        //floyd warshall
        for(int via = 0; via < n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    //if the distance from i to j via the city 'via' is less than the direct distance from i to j
                    adj[i][j] = min(adj[i][j],adj[i][via]+adj[via][j]);
                }
            }
        }
        
        int city = 0, min_adj_city = n;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(i!=j && adj[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=min_adj_city){
                city = i;
                min_adj_city = count;
            }
        }
        
        return city;
    }
};