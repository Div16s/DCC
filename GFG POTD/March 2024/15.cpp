/*
Difficulty: Medium
Problem Name: Linked List that is Sorted Alternatingly
Problem Link: https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1
Concepts Used: Linked List Traversal, Linked List Merging, Linked List Reversal
TC: 
SC: O(n2) reversing the second half of the linked list (recursion stack space)
*/

#include<bits/stdc++.h>
using namespace std;

/* Structure of the node of the linked list */
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};


class Solution
{
    public:
    // function to reverse a linked list
    Node* reverse(Node* head){
        if(!head->next) return head;
        Node* newHead = reverse(head->next);
        Node* front = head->next;
        front->next = head;
        head->next = NULL;
        
        return newHead;
    }
    
    public:
    // function to merge two sorted linked lists
    Node* mergeLinkedLists(Node* head1,Node* head2){
        Node* t1 = head1;
        Node* t2 = head2;
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;
        
        while(t1 && t2){
            if(t1->data < t2->data){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        
        if(t1){
            temp->next = t1;
        }
        else{
            temp->next = t2;
        }
        
        return dummyNode->next;
    }
    
    public:
    // your task is to complete this function
    void sort(Node **head)
    {
         // linkedlist is empty or has exactly one node
         if(!(*head) || !(*head)->next){
             return;
         }
         
         Node *head1 = *head;
         Node *head2 = (*head)->next;
         
         //splitting the linkedlist in two lists
         Node *first = head1;
         Node* second = head2;
         
         while(first->next && first->next->next){
             first->next = second->next;
             second->next = first->next->next;
             
             first = first->next;
             second = second->next;
         }
         
         
         first->next = NULL;
         
         //reversing the second list
         Node *reversed_list_head = reverse(head2);
         
         //merging the two lists
         *head = mergeLinkedLists(head1,reversed_list_head);
    }
};