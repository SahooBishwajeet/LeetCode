// 343. Integer Break
/* Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
Return the maximum product you can get.
*/

/*
Example 1:
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 

Constraints:
1. 2 <= n <= 58
*/

/*
=> Using Basic Observation & Logic to solve the problem

=> If the number is less than 3, then we can divide the number in a way to maximise the product by taking (2,1) for 3 and (1, 1) for 2 
=> If the number is Divisible by 3, then break it into parts of 3
=> If the number leaves 1 as remainder when divided by 3, then take as many 3 as possible and take the last 3, add 1 (remainder) to it and product is maximised
=> Similarly if remainder is 2, then we can take all 3 and the last 2, as adding 2 to the last 3 will make 5 but keeping it as it is will make it 6
*/

class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3) return n - 1;

        int quotient = n / 3, remainder = n % 3;
        if(remainder == 0) return pow(3, quotient);
        if(remainder == 1) return pow(3, quotient - 1) * 4;

        return pow(3, quotient) * 2;
    }
};
