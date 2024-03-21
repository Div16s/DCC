/*
Difficulty: Easy
Problem Name: 206. Reverse Linked List
Problem Link: https://leetcode.com/problems/reverse-linked-list/description/?envType=daily-question&envId=2024-03-21
Concepts Used: Linked List Traversal, Linked List Connection, Recursion
TC:  O(b+length of list2) traversing list1 till the b-th node and traversing list2 till the end
SC: O(1) using no extra space
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//iterative method
//TC: O(n) SC: O(1)
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};

//Recursive method
//TC: O(n) SC: O(n) due to recursion stack
class Solution {
public:
    ListNode* f(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* newHead = f(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }
public:
    ListNode* reverseList(ListNode* head) {
        return f(head);
    }
};
