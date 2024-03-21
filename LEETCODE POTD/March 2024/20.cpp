/*
Difficulty: Medium
Problem Name: 1669. Merge In Between Linked Lists
Problem Link: https://leetcode.com/problems/merge-in-between-linked-lists/description/?envType=daily-question&envId=2024-03-20
Concepts Used: Two pointers, Linked List Traversal, Linked List Connection
TC:  O(b+length of list2) traversing list1 till the b-th node and traversing list2 till the end
SC: O(1) using no extra space
*/

#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* left = nullptr;
        ListNode* right = list1;
        
        //traversing list1 till the b-th node
        for(int node_ind = 0; node_ind<=b; node_ind++){
            if(node_ind == a-1){
                left = right;
            }
            right = right->next;
        }
        
        //connecting the left node to the head of list2
        left->next = list2;

        //traversing list2 till the end
        ListNode* temp = list2;
        while(temp->next!=nullptr){
            temp = temp->next;
        }

        //connecting the last node of list2 to the right node
        temp->next = right;

        return list1;
    }
};