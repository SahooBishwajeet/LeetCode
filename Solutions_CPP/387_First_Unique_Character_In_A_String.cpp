// 387. First Unique Character in a String
// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
/*
Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1

Constraints:
1. 1 <= s.length <= 105
2. s consists of only lowercase English letters.
*/

/*
=> Storing frequency of all elements and accessing first element with frequency == 1
=> We need 2 loops, One to store the frequency and the Other to get the first element with frequency = 1
*/

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<int> freq(26,0);    // Initialising array to store frequency

        // Loop to Store Frequency
        for(int i = 0; s[i] != '\0'; i++)
            freq[s[i] - 'a']++;             // Getting ASCII Value Of The Character And Using That To Store Frequency
        
        // Loop to Find 1st Element With Frequency = 1
        for(int i = 0; s[i] != '\0'; i++)
            if(freq[s[i] - 'a'] == 1)
                return i;
        
        return -1;
    }
};
