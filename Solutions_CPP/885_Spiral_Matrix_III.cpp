// 885 : Spiral Matrix III

/*
You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.
You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.
Return an array of coordinates representing the positions of the grid in the order you visited them.
 

*/

/*
Example 1:


Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]

Example 2:


Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]

 

*/

/*
Constraints:

1 <= rows, cols <= 100
0 <= rStart < rows
0 <= cStart < cols


*/

/*
=> We can use simple simulation to solve this problem.

=> What we are asked is to rotate around the matrix in a clockwise manner starting from going east.
=> And if we ever go out of bounds, then we should follow the virtual path and eventually return to the original matrix path.

=> Since we have to move in a particular order, we can store the directions in this manner :
    East  : x  , y+1
    South : x+1, y
    West  : x  , y-1
    North : x-1, y

=> And we can store the increment/decrement for these directions in a vector

=> After every 2 iterations, we have to increase the steps taken in the direction, so as to loop around the matrix.
=> And we can store the pair {row, col} in the result vector, which is to be returned.

=> Time complexity : O(max(rows, cols) ^ 2)
*/

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;

        // East  : x  , y+1
        // South : x+1, y
        // West  : x  , y-1
        // North : x-1, y

        vector<vector<int>> dxy{{0,1},
                               {1,0},
                               {0,-1},
                               {-1,0}};

        int step = 1, dir = 0;

        while(res.size() < rows * cols) {
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < step; j++) {
                    if(rStart >= 0 && rStart < rows & cStart >= 0 && cStart < cols) {
                        res.push_back({rStart, cStart});
                    }

                    rStart += dxy[dir][0];
                    cStart += dxy[dir][1];
                }

                dir = (dir + 1) % 4;
            }

            step++;
        }

        return res;
    }
};