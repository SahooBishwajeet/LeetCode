// 119. Pascal's Triangle II
/*Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/
/*
Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1]
 

Constraints:
1. 0 <= rowIndex <= 33
*/

/*
=> Using Combinatorics to solve the problem

=> We can use Mirror Formula to get the value of the Next Term from the Previous Term
=> Next = Prev * (r - k + 1) / k, which can be derived from the formula nCr = n!/(n-r)!r!
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> res(1, 1);

        long long prevVal = 1;
        for(int k = 1; k <= rowIndex; k++) {
            long long nextVal = prevVal * (rowIndex - k + 1) / k;
            res.push_back(nextVal);
            prevVal = nextVal;
        }

        return res;
    }
};
