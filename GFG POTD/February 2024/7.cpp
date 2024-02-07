/*
Difficulty: Medium
Problem Name: Min distance between two given nodes of a Binary Tree
Problem Link: https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
Concept Used: Binary Tree, BFS, map, set
TC: O(n) n is number of nodes in binary tree
SC: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

/* A binary tree node */
struct Node
{
    int data;
    Node* left, * right;
};

class Solution{
    public:
    Node* markParent(int a,Node* root,unordered_map<Node*,Node*> &parent){
        queue<pair<Node*,Node*>> q;
        q.push({root,NULL});
        
        Node* source;
        
        while(!q.empty()){
            Node* curr_node = q.front().first;
            Node* par = q.front().second;
            q.pop();
            
            if(curr_node->data==a) source = curr_node;
            
            parent[curr_node] = par;
            
            if(curr_node->left){
                q.push({curr_node->left,curr_node});
            }
            if(curr_node->right){
                q.push({curr_node->right,curr_node});
            }
        }
        
        return source;
    }
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        // Your code here
        unordered_map<Node*,Node*> parent;
        Node* source = markParent(a,root,parent);
        
        set<Node*> vis;
        queue<pair<Node*,int>> q;
        q.push({source,0});
        vis.insert(source);
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* curr_node = it.first;
            int dist = it.second;
            
            if(curr_node->data == b) return dist;
            
            if(curr_node->left && !vis.count(curr_node->left)){
                q.push({curr_node->left,dist+1});
                vis.insert(curr_node->left);
            }
            if(curr_node->right && !vis.count(curr_node->right)){
                q.push({curr_node->right,dist+1});
                vis.insert(curr_node->right);
            }
            if(parent[curr_node] && !vis.count(parent[curr_node])){
                q.push({parent[curr_node],dist+1});
                vis.insert(parent[curr_node]);
            }
        }
        
        return 0;
        
    }
};