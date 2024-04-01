/*
Difficulty: Medium
Problem Name: Pairs violating the BST property
Problem Link: https://geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1
Concepts Used: Binary Search Tree, Inversions, Merge Sort
TC: O(nlogn + n) inOrder traversal + for the merge sort and counting the inversions
SC: O(n) for the inOrder traversal
*/

#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

class Solution {
  public:
    //inOrder traversal of the tree
    void inorderTraversal(Node* root, vector<int>&nodes){
        if(!root) return;
        inorderTraversal(root->left,nodes);
        nodes.push_back(root->data);
        inorderTraversal(root->right,nodes);
    }
    
  public:
    int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr
    
        //Modification 1: cnt variable to count the pairs:
        int cnt = 0;
    
        //storing elements in the temporary array in a sorted manner//
    
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1); //Modification 2
                right++;
            }
        }
    
        // if elements on the left half are still left //
    
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
    
        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
    
        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    
        return cnt; // Modification 3
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2 ;
        cnt += mergeSort(arr, low, mid);  // left half
        cnt += mergeSort(arr, mid + 1, high); // right half
        cnt += merge(arr, low, mid, high);  // merging sorted halves
        return cnt;
    }
    
    int numberOfInversions(vector<int>&a, int n) {
    
        // Count the number of pairs:
        return mergeSort(a, 0, n - 1);
    }  
  public:
    
    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        int count=0;
        vector<int> nodes;
        inorderTraversal(root,nodes);
        
        count = numberOfInversions(nodes,n);
        
        return count;
    }
};