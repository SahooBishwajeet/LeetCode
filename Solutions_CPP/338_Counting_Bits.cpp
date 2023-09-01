// 338 Counting Bits
/* Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
*/

/*
Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:
1. 0 <= n <= 105
*/

/*
=> We can use Dynamic Programming to solve the problem.

=> Number of 1s in ith number is same as number of 1s in i/2th number + shifted bit (can be found after &ing with 1) 
=> We use a vector to store the number of 1s in each index
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        for(int i = 0; i <= n; i++){
            ans[i] = ans[i>>1] + (i&1); // Number of 1s in ith number is same as number of 1s in i/2th number + shifted bit (can be found after &ing with 1) 
        }

        return ans;
    }
};
