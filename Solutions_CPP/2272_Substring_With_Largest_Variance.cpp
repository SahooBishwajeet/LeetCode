// 2272. Substring With Largest Variance
/* The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.
Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.
A substring is a contiguous sequence of characters within a string.
*/

/*
Example 1:
Input: s = "aababbb"
Output: 3
Explanation:
All possible variances along with their respective substrings are listed below:
- Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
- Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
- Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
- Variance 3 for substring "babbb".
Since the largest possible variance is 3, we return it.

Example 2:
Input: s = "abcde"
Output: 0
Explanation:
No letter occurs more than once in s, so the variance of every substring is 0.
 

Constraints:
1. 1 <= s.length <= 104
2. s consists of lowercase English letters.

/*
=> Using Kadane Algorithm to solve the problem

=> We iterate through the string and store frequency of 2 characters as we iterate.
=> We also update the Max Length of required substring if necessary.

=> When the frequency of 1st character is less than 2nd character, we need to look for a new substring.....So we reinitialise frequency counter.
=> We also need to check for reversed string as a single character at the start won't be considered in the counting with hthis algorithm.
*/
class Solution {
public:
    int largestVariance(string s) {
        vector<int>arr(26);
        for(auto x:s){
           arr[x-'a']++; 
        }
        int ans=0;
        for(char i='a';i<='z';i++){
            for(char j='a';j<='z';j++){
                 if(j==i||arr[i-'a']==0||arr[j-'a']==0)
                            continue;
                for(int k=1;k<=2;k++){
                   int c1=0;
                    int c2=0;
                    for(auto x:s){
                        if(x==i)
                            c1++;
                        if(x==j)
                            c2++;
                        if(c2>c1){
                            c1=0;
                            c2=0;
                        }
                        if(c1>0&&c2>0)
                        ans=max(ans,c1-c2);
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};
