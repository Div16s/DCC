/*
Difficulty: Medium
Problem Name: Euler Circuit in an Undirected Graph
Problem Link: https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1
Concepts Used: Graphs, Euler Circuit, DFS, Connected Graph, Degree of a node
TC: O(V+E) where V is the number of vertices and E is the number of edges
SC: O(V) for the vis array
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //performing dfs
    void dfs(int node, vector<bool>&vis, vector<int>adj[]){
        vis[node]=true;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i,vis,adj);
            }
        }
    }
    //Function to check if all non-zero degree vertices are connected.
    bool connected_graph(int v, vector<int>adj[]){
        vector<bool> vis(v,false);
        int start_node = -1;
        for(int i=0; i<v; i++){
            if(adj[i].size()){
                start_node = i;
                break;
            }
        }
        
        if(start_node==-1){
            return true;
        }
        
        dfs(start_node,vis,adj);
        for(int i=0; i<v; i++){
            if(!vis[i] && adj[i].size()>0){
                return false;
            }
        }
        
        return true;
    }
public:
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    // Code here
        //checking if the graph is connected
	    if(!connected_graph(v,adj)){ 
	        return false;
	    }
	    
	    int odd_degree_nodes = 0;
	    for(int i=0; i<v; i++){
	        if(adj[i].size() & 1){ //if the degree of the node is odd
	            odd_degree_nodes++;
	        }
	    }
	    
	    return (odd_degree_nodes==0);
	}

};