// 796 : Rotate String

/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.

 

*/

/*
Example 1:
Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:
Input: s = "abcde", goal = "abced"
Output: false

 

*/

/*
Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.


*/

/*
- We can simply perform the operation asked in the problem statement

- To do the rotation, we can use the inbuilt rotate function to rotate the array in the desired format
- rotate(begin, begin + 1, end) for left rotation & rotate(rbegin, rbegin + 1, rend) for right rotation
- After each rotation, we check if the rotated string is equal to the goal string
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        for(int i = 0; i < s.size(); i++) {
            rotate(s.begin(), s.begin() + 1, s.end());

            if(s == goal) return true;
        }

        return false;
    }
};