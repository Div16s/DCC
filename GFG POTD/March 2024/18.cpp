/*
Difficulty: Easy
Problem Name: Level Order Traversal
Problem Link: https://www.geeksforgeeks.org/problems/level-order-traversal/1
Concepts Used: BFS, Tree Traversal
TC: O(n) n is the number of nodes in the tree
SC: O(n) storing nodes in queue during BFS
*/

#include<bits/stdc++.h>
using namespace std;

/* A binary tree Node */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      //Your code here
      vector<int> ans;
      queue<Node*> q;
      q.push(root);
      
      while(!q.empty()){
          auto curr_node = q.front();
          q.pop();
          
          ans.push_back(curr_node->data);
          if(curr_node->left){
              q.push(curr_node->left);
          }
          if(curr_node->right){
              q.push(curr_node->right);
          }
          
      }
      
      return ans;
    }
};