// 459. Repeated Substring Pattern
/* Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
*/

/*
Example 1:
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.

Example 2:
Input: s = "aba"
Output: false

Example 3:
Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 
Constraints:
1. 1 <= s.length <= 104
2. s consists of lowercase English letters.
*/

/*
=> We can use String Manipulation to solve the problem.

=> We know a fact that if we concatenate the string with itself and delete the First & Last element, then if the SubString is present in the new string 
then it can form the entire string with repetition.
 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string concat = s + s;
        string subStr = concat.substr(1, concat.size() - 2);
        return subStr.find(s) != string::npos;
    }
};
