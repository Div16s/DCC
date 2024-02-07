/*
Difficulty: Medium
Problem Name: 451. Sort Characters By Frequency
Problem Link: https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07
Concepts Used: Strings
TC: O(n)
SC: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int,char>&a, pair<int,char>&b){
        return a.first>b.first;
    }

    string frequencySort(string s) {
        int n = s.size();
        vector<pair<int,char>> freq(62);
        for(int i=0; i<62; i++){
            freq[i].first = 0;
        }
        string ans = "";
        for(int i=0; i<n; i++){
            if(s[i]>='A' && s[i]<='Z'){
                int ind = 10+s[i]-'A';
                int count = freq[ind].first;
                freq[ind] = {count+1,s[i]};
            }
            else if(s[i]>='a' && s[i]<='z'){
                int ind = 36+s[i]-'a';
                int count = freq[ind].first;
                freq[ind] = {count+1,s[i]};
            }
            else{
                int ind = s[i]-'0';
                int count = freq[ind].first;
                freq[ind] = {count+1,s[i]};
            }
        }

        sort(freq.begin(),freq.end(),cmp);

        for(int i=0; i<62; i++){
            int count = freq[i].first;
            while(count){
                ans+=freq[i].second;
                count--;
            }
        }

        return ans;
    }
};