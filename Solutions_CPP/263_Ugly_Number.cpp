// 263 : Ugly Number

/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return true if n is an ugly number.
 

*/

/*
Example 1:

Input: n = 6
Output: true
Explanation: 6 = 2 × 3

Example 2:

Input: n = 1
Output: true
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

Example 3:

Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.

 

*/

/*
Constraints:

-231 <= n <= 231 - 1


*/

/*
=> Take the number & keep on dividing it by 2,3,5
=> Of course, we need to check if the number is divisible by 2,3,5 or not
=> If at any point, the number is not divisible by 2,3,5, then there exists some other factor which is not 2,3,5
=> So, the number is not ugly
*/

class Solution {
public:
    bool isUgly(int n) {
        if(n == 0) return false;

        while(n > 1) {
            if(n % 2 == 0) {
                n = n / 2;
            } else if(n % 3 == 0) {
                n = n / 3;
            } else if(n % 5 == 0) {
                n = n / 5;
            } else {
                break;
            }
        }
        
        return n == 1;
    }
};