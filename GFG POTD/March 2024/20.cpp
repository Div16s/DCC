/*
Difficulty: Medium
Problem Name: Sum of nodes on the longest path from root to leaf node
Problem Link: https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
Concepts Used: Tree Traversal, DFS
TC: O(n) traversing all nodes of the tree
SC: O(n) using the call stack for recursion
*/

#include<bits/stdc++.h>
using namespace std;

//structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void f(Node* root, int curr_path_length, int &path_length,int sum, int &ans){
        if(!root){
            return;
        }
        
        //adding the current node's data to the sum and incrementing the current path length
        sum+=root->data;
        curr_path_length++;

        //if the current node is a leaf node
        if(!root->left && !root->right){
            if(curr_path_length==path_length){
                ans = max(ans,sum);
            }
            else if(curr_path_length>path_length){
                ans = sum;
                path_length = max(path_length,curr_path_length);
            }
        }
        
        //recursively calling the left and right subtrees
        f(root->left,curr_path_length,path_length,sum,ans);
        f(root->right,curr_path_length,path_length,sum,ans);
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int ans = 0; 
        int sum = 0;
        int path_length = 0;
        int curr_path_length = 0;

        //calling the helper function to find the sum of the longest path from root to leaf
        f(root,curr_path_length,path_length,sum,ans);

        return ans;
    }
};