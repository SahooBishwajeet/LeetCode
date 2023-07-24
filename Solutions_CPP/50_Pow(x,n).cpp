// 50. Pow(x, n)
/* Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/

/*
Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:
1. -100.0 < x < 100.0
2. -231 <= n <= 231-1
3. n is an integer.
4. Either x is not zero or n > 0.
5. -104 <= xn <= 104
*/

/*
=> We use Recursion to solve the problem.

=> The myPow function takes two parameters: x (the base) and n (the exponent).
=> Inside myPow, it calls the helper function, passing x and the absolute value of n.
=> The helper function recursively calculates the power of x raised to n, using the following steps:
    a. If n is 0, it returns 1 since any number raised to the power of 0 is 1.
    b. Otherwise, it calculates temp, which is the result of myPow(x, n/2). This is done to reduce redundant calculations and improve the efficiency.
    c. It squares temp to handle even exponents (n%2==0). If the exponent is odd, it multiplies temp by x.
    d. The function then returns the calculated result.
*/
class Solution {
public:
    double helper(double x, int n) {
        if(n==0)
            return 1;
        
        double tempVar = myPow(x,n/2);
        if(n%2 == 0)
            return tempVar*tempVar;
        else
            return tempVar*tempVar*x;
    }
    double myPow(double x, int n) {
        double ans = helper(x,abs(n));
        if(n<0)
            return 1/ans;
        return ans;
       
    }
};
