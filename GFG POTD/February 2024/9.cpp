/*
Difficulty: Medium
Problem Name: Check for Children Sum Property in a Binary Tree
Problem Link: https://www.geeksforgeeks.org/problems/children-sum-parent/1
Concepts Used: Tree Traversal
TC: O(n) n is number of nodes
SC: O(h) height of the tree
*/

#include<bits/stdc++.h>
using namespace std;

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

class Solution{
    public:
    int f(Node* root, bool &flag){
        if(!root) return 0;
        if(!root->left && !root->right) return root->data;
        int curr_val = root->data;
        int left_val = f(root->left,flag);
        int right_val = f(root->right,flag);
        if(curr_val!=(left_val+right_val)) flag=false;
        
        return curr_val;
    }
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     bool flag = true;
     int val = f(root,flag);
     return (flag);
    }
};