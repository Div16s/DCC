/*
Difficulty: Medium
Problem Name: Game with String
Problem Link: https://www.geeksforgeeks.org/problems/game-with-string4100/1
Concepts Used: Greedy & Priority Queue
TC: O(n) + O(klogp), n is the size of string, k is the number of characters to be removed, p is the distinct characters
SC: O(n) 
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution{
public:
    int minValue(string s, int k){
        // code here
        int n = s.size();
        vector<int> freq(26,0);
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        
        priority_queue<int> pq;
        for(int i=0; i<26; i++){
            if(freq[i]!=0) pq.push(freq[i]);
        }
        
        while(k){
            int curr = pq.top();
            pq.pop();
            curr--;
            pq.push(curr);
            k--;
        }
        
        ll ans = 0;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            ans+=(x*x);
        }
        
        return ans;
    }
};