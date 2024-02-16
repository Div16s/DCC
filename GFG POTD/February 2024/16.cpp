/*
Difficulty: Medium
Problem Name: Flatten BST to sorted list
Problem Link: https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1
Concepts Used: Recursion & Binary Tree Traversal
TC: O(n) n is number of nodes
SC: O(n) 
*/

#include<bits/stdc++.h>
using namespace std;

/* Node of the binary search tree */
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution
{
public:
    void f(vector<Node*> &ans, Node* root){
        if(!root) return;
        f(ans,root->left);
        ans.push_back(root);
        f(ans,root->right);
    }
    
    Node *flattenBST(Node *root)
    {
        // code here
        vector<Node*> ans;
        f(ans, root);
        Node* head = nullptr, *prev = nullptr;
        if (!ans.empty()) {
            head = ans[0];
            head->left = nullptr;
            prev = head;
            for (int i = 1; i < ans.size(); i++) {
                prev->right = ans[i];
                ans[i]->left = NULL;
                prev = ans[i];
            }
        }
        return head;
    }
};