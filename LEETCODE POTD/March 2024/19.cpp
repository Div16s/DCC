/*
Difficulty: Medium
Problem Name: 57. Insert Interval
Problem Link: https://leetcode.com/problems/insert-interval/description/?envType=daily-question&envId=2024-03-17
Concepts Used: Range Overlapping, Range Merging
TC: O(n) traversing all intervals 
SC: O(1) using no space other than storing non-overlapping intervals after inserting the newInterval
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int break_ind = n;
        for(int i=0; i<n; i++){
            int currInterval_start = intervals[i][0];
            int currInterval_end = intervals[i][1];
            //if current Interval's end is less than new Interval's start
            // curr_start------curr_end  new_start------new_end
            if(currInterval_end < newInterval[0]){
                ans.push_back(intervals[i]); //push current interval as it is
            }
            else if(currInterval_start > newInterval[1]){ //if current Interval's start is greater than new Interval's end
                break_ind = i;
                break;
            }
            else{
                //merging the overlapping intervals
                // curr_start------curr_end      OR       curr_start------curr_end
                //      new_start------new_end        new_start------new_end
                newInterval[0] = min(newInterval[0],currInterval_start);
                newInterval[1] = max(newInterval[1],currInterval_end);
            }
        }
        
        //pushing the new interval after merging(if it overlaps with any interval)
        ans.push_back(newInterval);
        
        //pushing the remaining intervals after the new interval
        for(int i=break_ind; i<n; i++){
            ans.push_back(intervals[i]);
        }

        return ans;
    }
};