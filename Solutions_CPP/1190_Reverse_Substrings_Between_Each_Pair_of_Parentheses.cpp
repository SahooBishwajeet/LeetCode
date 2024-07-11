// 1190 : Reverse Substrings Between Each Pair of Parentheses

/*
You are given a string s that consists of lower case English letters and brackets.
Reverse the strings in each pair of matching parentheses, starting from the innermost one.
Your result should not contain any brackets.
 

*/

/*
Example 1:

Input: s = "(abcd)"
Output: "dcba"

Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

 

*/

/*
Constraints:

1 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It is guaranteed that all parentheses are balanced.


*/

/*
=> We can use wormhole teleportation to solve this problem. (Thought the naive approach using stack is simpler but of O(n^2) complexity)

=> In one pass we need to pair the opening and closing brackets.
=> We can store these pairs as links connecting each other.

=> In another pass we will traverse & build the result.
=> To do that, while traversing when we encounter an opening bracket, we will jump to the corresponding closing bracket.
=> And reverse traversal direction while pushing onto our result variable.
=> Similarly, when we encounter a closing bracket, we will jump to the corresponding opening bracket.
=> And reverse traversal direction while pushing onto our result variable.
*/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        vector<int> pair(s.size());

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') st.push(i);
            if(s[i] == ')') {
                int j = st.top();
                st.pop();

                pair[i] = j;
                pair[j] = i;
            }
        }

        string res;
        bool forward = true;
        for(int i = 0; i < s.size(); i = forward ? i+1 : i-1) {
            if(s[i] == '(' || s[i] == ')') {
                i = pair[i];
                forward = !forward;
            } else {
                res += s[i];
            }
        }

        return res;
    }
};