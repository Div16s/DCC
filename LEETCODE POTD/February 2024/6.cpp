/*
Difficulty: Medium
Problem Name: 49. Group Anagrams
Problem Link: https://leetcode.com/problems/group-anagrams/description/?envType=daily-question&envId=2024-02-06
Concepts Used: Strings, Anagrams, Map
TC: O(n)
SC: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string find(string &s){
        vector<int> freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }

        string new_word="";
        for(int i=0; i<26; i++){
            if(freq[i]>0){
                new_word+=string(freq[i],i+'a');
            }
        }

        return new_word;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        
        unordered_map<string, vector<string>>mp;
        
        for(int i = 0 ; i < strs.size() ; i++)
        {
            string s = strs[i];
            string new_word = find(s);
            mp[new_word].push_back(s);
        }
        
        for(auto i : mp)
        {
            ans.push_back(i.second);
        }

        return ans;
    }
};