// 2406 : Divide Intervals Into Minimum Number of Groups

/*
You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].
You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.
Return the minimum number of groups you need to make.
Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.
 

*/

/*
Example 1:

Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
Output: 3
Explanation: We can divide the intervals into the following groups:
- Group 1: [1, 5], [6, 8].
- Group 2: [2, 3], [5, 10].
- Group 3: [1, 10].
It can be proven that it is not possible to divide the intervals into fewer than 3 groups.

Example 2:

Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
Output: 1
Explanation: None of the intervals overlap, so we can put all of them in one group.

 

*/

/*
Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
1 <= lefti <= righti <= 106


*/

/*
- The problem asks us to find the minimum number of groups that can be formed from the given intervals.
- But properly visualising the problems helps us see it in another way i.e. what is the maximum number of overlapping intervals at any point of time.

- We can find it by running a line sweep from left to right
    - If we find a start of an interval, we increase the number of groups by 1
    - If we find an end of an interval, we decrease the number of groups by 1
    - Note : We first choose the start over the end because we are told that the numbers are inclusive & hence it contributes to the overlapping
    - We keep track of the maximum number of groups at any point of time
*/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;

        for(auto& interval:intervals) {
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0, j = 0, res = 0, grp = 0;

        while(i<intervals.size()) {
            if(start[i] <= end[j]) {
                grp+=1;
                i+=1;
            } else {
                grp-=1;
                j+=1;
            }

            res = max(res, grp);
        }

        return res;
    }
};