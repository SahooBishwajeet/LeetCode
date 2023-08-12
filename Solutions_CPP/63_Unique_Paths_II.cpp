// 63. Unique Paths II
/* You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.
*/

/*
Example 1:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 
Constraints:
1. m == obstacleGrid.length
2. n == obstacleGrid[i].length
3. 1 <= m, n <= 100
4. obstacleGrid[i][j] is 0 or 1.
*/

/*
=> We can use Dynamic Programming to solve the problem.

=> We would have a dp array of size m x n, where dp[i][j] represents the number of ways to reach cell (i, j).
  The transition formula would be:
    dp[i][j]={0,                     if obstacleGrid[i][j]=1;
              dp[i−1][j]+dp[i][j−1], otherwise}

So, for each cell (i, j), if there's no obstacle, its value would be the sum of the cell above it and the cell to its left. 

=> Now we can break this 2-D DP into 1-D DP as:
   2D dp array to two 1D arrays, previous and current.

The transition formula in 1D would be analogous to the 2D version but slightly adjusted:

For the first column (j = 0):
current[0]={0,           if obstacleGrid[i][0]=1;
            previous[0], otherwise}

For other columns:
current[j]={0,                        if obstacleGrid[i][j]=1; 
            previous[j]+current[j−1], otherwise}

Here, previous is analogous to dp[i-1] and current is analogous to dp[i] from our 2D approach. After processing each row, we'll swap previous and current to roll over to the next iteration.
*/
class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        std::vector<int> previous(n, 0);
        std::vector<int> current(n, 0);
        previous[0] = 1;
        
        for (int i = 0; i < m; i++) {
            current[0] = obstacleGrid[i][0] == 1 ? 0 : previous[0];
            for (int j = 1; j < n; j++) {
                current[j] = obstacleGrid[i][j] == 1 ? 0 : current[j-1] + previous[j];
            }
            previous = current;
        }
        
        return previous[n-1];
    }
};
