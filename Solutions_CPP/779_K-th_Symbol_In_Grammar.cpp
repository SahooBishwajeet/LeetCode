// 779. K-th Symbol in Grammar
/* We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.

*/

/*
Example 1:
Input: n = 1, k = 1
Output: 0
Explanation: row 1: 0

Example 2:
Input: n = 2, k = 1
Output: 0
Explanation: 
row 1: 0
row 2: 01

Example 3:
Input: n = 2, k = 2
Output: 1
Explanation: 
row 1: 0
row 2: 01
 
Constraints:
1. 1 <= n <= 30
2. 1 <= k <= 2n - 1
*/

/*
 => Using Iteration & Pattern Observation to solve this problem
 
 => We can observe that every next level's 1st half is the exact copy of the previous level and the 2nd half is the complement of the previous level. 
 => So we can use this to either recursively or iterativey find the kth symbol in the nth row.
 => For example if n = 2 and k = 2, we can see that it is the complement of k = 1

 => Time Complexity: O(n), Space Complexity: O(1)
 */

class Solution {
public:
    int kthGrammar(int n, int k) {
        int length = pow(2, n);
        bool flag = true;

        while(length != 1) {
            length /= 2;

            if(k > length) {
                k -= length;
                flag = !flag;
            }
        }
        return flag ? 0 : 1;
    }
};
