/*
Difficulty: Easy
Problem Name: 387. First Unique Character in a String
Problem Link: https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05
TC: O(n)
SC: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        vector<int> freq(26,0);
        vector<bool> previously_seen(26,false);
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }

        int ans = -1;
        for(int i=0; i<n; i++){
            freq[s[i]-'a']--;
            if(freq[s[i]-'a']==0 && !previously_seen[s[i]-'a']){
                ans = i;
                break;
            }
            else{
                previously_seen[s[i]-'a']=true;
            }
        }

        return ans;
    }
};