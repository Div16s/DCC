/*
Difficulty: Medium
Problem Name: 452. Minimum Number of Arrows to Burst Balloons
Problem Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=daily-question&envId=2024-03-18
Concepts Used: Range Overlapping + Sorting
TC: O(nlogn) 
SC: O(1) 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int prev_start = points[0][0];
        int prev_end = points[0][1];
        int arrows = 1;
        for(int i=1; i<n; i++){
            if(points[i][0]>prev_end){
                arrows++;
                prev_start = points[i][0];
                prev_end = points[i][1];
            }
            else{
                prev_start = max(prev_start,points[i][0]);
                prev_end = min(prev_end,points[i][1]);
            }
        }

        return arrows;
    }
};