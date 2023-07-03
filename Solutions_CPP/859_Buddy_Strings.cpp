// 859. Buddy Strings
/* Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
*/

/*
Example 1:
Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

Example 2:
Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

Example 3:
Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.

Constraints:
1. 1 <= s.length, goal.length <= 2 * 104
2. s and goal consist of lowercase letters.
*/

/*
=> First check if both are identical. [ If both are identical, then we need to check unique characters present in both the strings (store in a Set) ]

=> If not, then iterate over the 's' to find out 1st unidentical character
=> Then iterate from end to find 2nd unidentical character
=> Swap the unidentical characters and check if 's' and 'goal' became same or not
*/
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();

        // If both are identical, then we need to check unique characters present in both the strings (store in a Set)
        if(s == goal){
            set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size(); // CASE = Swapping duplicate characters 
        }

        int i = 0;
        int j = n - 1;

        while(i < j && s[i] == goal[i]){
            i++;
        }

        while(j >= 0 && s[j] == goal[j]){
            j--;
        }

        if(i < j){
            swap(s[i], s[j]);
        }

        return s == goal;
    }
};
