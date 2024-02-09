/*
Difficulty: Easy
Problem Name: Check if all leaves are at same level
Problem Link: https://www.geeksforgeeks.org/problems/leaf-at-same-level/1
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
    void f(Node* root, int curr_level, set<int>&level){
        if(!root) return;
        if(!root->left && !root->right){
            level.insert(curr_level);
            return;
        }
        
        f(root->left,curr_level+1,level);
        f(root->right,curr_level+1,level);
    }
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        if(!root) return true;
        set<int> level;
        f(root,1,level);
        
        if(level.size()==1) return true;
        return false;
    }
};