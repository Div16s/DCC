/*
Difficulty: Medium
Problem Name: ZigZag Tree Traversal
Problem Link: https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1
Concepts Used: Tree Traversal, BFS, Queue
TC: O(n) traversing all nodes of the tree exactly once
SC: O(n) using the queue to store the nodes of the tree
*/

#include<bits/stdc++.h>
using namespace std;


/*Structure of the node of the binary tree is as*/
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	int level = 0; //to keep track of the level of the tree
    	vector<int> ans; 
    	queue<Node*> q; //queue to store the nodes of the tree
    	q.push(root);

        //traversing the tree level by level (BFS traversal)
    	while(!q.empty()){ //it will run for all the levels of the tree(max level can be log(n) where n is the number of nodes in the tree
    	    int size = q.size();
    	    vector<int> temp;
            //traversing the nodes of the current level
    	    for(int i=0; i<size; i++){
    	        Node* node = q.front();
    	        q.pop();
    	        
    	        temp.push_back(node->data);
    	        if(node->left) q.push(node->left);
    	        if(node->right) q.push(node->right);
    	    }
    	    
            //if the level is odd, we need to reverse the nodes of the current level                
    	    if(level&1){
    	        for(int i=temp.size()-1; i>=0; i--){
    	            ans.push_back(temp[i]);
    	        }
    	    }
    	    else{ //if the level is even, we need to push the nodes as it is
    	        for(int i=0; i<temp.size(); i++){
    	            ans.push_back(temp[i]);
    	        }
    	    }
    	    
            //incrementing the level
    	    level++;
    	}
    	
    	return ans;
    }
};