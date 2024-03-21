/*
Difficulty: Easy
Problem Name: Count Pairs whose sum is equal to X
Problem Link: https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1
Concepts Used: Hashing, Linked List Traversal
TC: O(length of linked list 1) + O(length of linked list 2)
SC: O(length of linked list 1) storing the linked list 1 in a map
*/

#include<bits/stdc++.h>
using namespace std;

/* Structure of the node of the linked list */
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        int pairs = 0;

        map<int,int> mp;
        Node* curr = head1;
        //storing the first linked list in a map
        while(curr){
            int val = curr->data;
            mp[val]=1;
            curr = curr->next;
        }
        
        curr = head2;
        //traversing the second linked list and checking if the required value to make a pair is present in the map
        while(curr){
            int val = curr->data;
            int req_val = x-val;
            //if the required value is present in the map, increment the pairs count
            if(mp.find(req_val)!=mp.end()){
                pairs++;
            }
            curr = curr->next;
        }
        
        return pairs;
    }
};