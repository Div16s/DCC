/*
Difficulty: Medium
Problem Name: Kth common ancestor in BST
Problem Link: https://www.geeksforgeeks.org/problems/kth-common-ancestor-in-bst/1
Concepts Used: Binary Search Tree, Lowest Common Ancestor, Path from root to LCA, Recursion
TC: O(h) for finding the LCA and O(h) for finding the path from root to LCA, h is the height of the tree
SC: O(h) for the recursion stack, h is the height of the tree
*/

#include<bits/stdc++.h>
using namespace std;

// A Tree node
struct Node
{
	int data;
	struct Node *left, *right;
};


class Solution
{
    public:
    //Function to find the lowest common ancestor in a BST.
    Node* findLCA(Node *root, int x, int y){
        if(!root) return NULL;
        
        //if root's data is equal to x or y, then the root is the LCA
        if(root->data==x || root->data==y) return root;
        
        //if root's data is less than x and y, then the LCA will be in the right subtree
        if(root->data<x && root->data<y){ //
            return findLCA(root->right,x,y);
        }
        //if root's data is greater than x and y, then the LCA will be in the left subtree
        if(root->data>x && root->data>y){
            return findLCA(root->left,x,y);
        }
        
        //if root's data is between x and y, then the root is the LCA
        return root;
    }
    
    public:
    //Function to find the path from root to the LCA.
    void findRootToLCAPath(Node *root, Node *LCA, vector<int>&path){
        path.push_back(root->data); 
        //if the root's data is equal to LCA's data, then return as the path is found
        if(root->data == LCA->data) return;
        
        //if the root's data is greater than LCA's data, then the LCA will be in the left subtree
        if(root->data > LCA->data){
            findRootToLCAPath(root->left, LCA, path);
        }
        else{ //if the root's data is less than LCA's data, then the LCA will be in the right subtree
            findRootToLCAPath(root->right, LCA, path);
        }
    }
    public:
    
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        Node *LCA = findLCA(root,x,y); 
        vector<int> path;
        findRootToLCAPath(root,LCA,path);
        //if the path size is less than k, then return -1
        if(path.size()<k) return -1;
        //return the kth element from the end of the path
        return path[path.size()-k];
    }
};

