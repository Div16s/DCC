/*
Difficulty: Medium
Problem Name: Minimum Absolute Difference In BST
Problem Link: https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1
Concepts Used: Binary Search Tree, InOrder Traversal -> Sorted Array
TC: O(n) for the inOrder traversal and finding the minimum difference by traversing, n is the number of nodes in the tree
SC: O(n) for the inOrder traversal
*/

#include<bits/stdc++.h>
using namespace std;

//The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;
};

class Solution
{
    public:
    //inOrder traversal of the tree
    void inOrder(Node *root, vector<int>&nodes){
        if(!root) return;
        inOrder(root->left,nodes);
        nodes.push_back(root->data);
        inOrder(root->right,nodes);
    }
    public:
    int absolute_diff(Node *root)
    {
        //Your code here
        int min_diff = INT_MAX;
        vector<int> nodes;
        inOrder(root,nodes); //inOrder traversal of the tree gives the sorted array of nodes
        for(int i=0; i<(nodes.size()-1); i++){ //finding the minimum difference by traversing the sorted array
            min_diff = min(min_diff,abs(nodes[i]-nodes[i+1]));
        }
        return min_diff;
    }
};
