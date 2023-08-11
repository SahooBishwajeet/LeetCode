// 518 Coin Change II
/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.
*/

/*
Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:
Input: amount = 10, coins = [10]
Output: 1
 

Constraints:
1. 1 <= coins.length <= 300
2. 1 <= coins[i] <= 5000
3. All the values of coins are unique.
4. 0 <= amount <= 5000
*/

/*
=> We can use Dinamic Programming to solve the problem.

=> To find the solution in an optimized manner, we use a one-dimensional array, dp, of size amount + 1, where dp[i] represents the number of ways to make up the amount i using the coins considered so far.
      Initialize dp with all zeros and set dp[0] to 1 since there's only one way to make up amount 0, which is by not choosing any coin.
      For each coin in coins, update the array dp from the coin value to the total amount.
      For each amount i from the coin value to the total amount, increment dp[i] by dp[i - coin_value].
      The final answer will be dp[amount].
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }
        
        return dp[amount];
    }
};
