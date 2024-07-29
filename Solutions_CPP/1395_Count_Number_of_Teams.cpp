// 1395 : Count Number of Teams

/*
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).

Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).
 

*/

/*
Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 

Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.

Example 3:

Input: rating = [1,2,3,4]
Output: 4

 

*/

/*
Constraints:

n == rating.length
3 <= n <= 1000
1 <= rating[i] <= 105
All the integers in rating are unique.


*/

/*
- The problem is simple, we have to find number of 3-Num Pairs in ascending or descending order.
- i.e. for array = [2,5,3,4,1], we have (2,3,4) as ascending and (5,4,1), (5,3,1) as descending.

1. Brute Force:
- A naive approach would be to go through all the possible combinations of 3 numbers:
    - Loop through the array & choose 1st number
    - Go through the rest of the array & choose 2nd number
    - Here would come a decision point:
        - If 2nd number > 1st number, then 3rd number has to be greater than 2nd number.
        - If 2nd number < 1st number, then 3rd number has to be less than 2nd number.
    - After choosing 2nd number, go through the rest of the array & choose 3rd number based on the
      above decision.
- But the time complexity of this approach would be O(n^3), which would be a TLE for large inputs.

2. Dynamic Programming:
- To optimise this, we can use Dynamic Programming. (We'll do that after we learn DP)
- But here is the approach:
    - Have a memo to store calculated values
    - Loop through the array and choose an element as the first number

    - We have a decision to make i.e. whether go ascending or descending
    - We can have pass it as a boolean to the helper function
    - If boolean is true then we find ascending pairs for that number
    - Else we find descending pairs for that number

    - Siliar to all DP memo, if memo contains the val ue (i.e. it was calculated before), return it
    - Else go on to calculate the value

    - In the helper function we can take 3 params:
        - Index of the number chosen as first number
        - Boolean (Ascending or Descending)
        - Number of elements chosen till now

    - So, our base case would be:
        - If we have chosen 3 numbers, then return 1 (as we have found one valid 3-Num Pair)
        - If we have reached the end of array, then return 0 (as we have not found any valid 3-Num
          Pair)

    - In the helper function, we iterate over the remaining array & apply recursion i.e. the same
      function call to find the third number.
    - After finishing the recursion, we have the calculated value:
        - which we store in the memo
        - and return it to be added to the result

3. Interesting Approach (Changing the perspective):
- But let's see a very interesting approach to solve this problem.
- It is all about changing the perspective of the problem & the way we approach it.
- We are asked to find 3 numbers, so we start thinking by choosing the first number
  & the remaining 2 based on condition.
- This creates the problem as:
    - We have to deal with the decision point
    - Also, with 3rd number depending on 2nd, we are bound to have some expensive computation
     i.e. some kind of nested loops or decision tree in recursion.
- Picking the last element is same as picking the first element, as ascending from first is same as
  descending from last and same goes for descending from first and ascending from last.

- So, instead let's choose the middle element first.
- Now think if it helped us in any way or not.
- Our conditions :
    first < middle < last or first > middle > last
- So, after choosing the middle element, we have to just find number of elements eligible to be
  first & last in both the cases.
- Note: we don't have any decision point now.

- Let's see it with an exampe:
    - rating = [2,5,3,4,1]
    - Let's say in some ith iteration, we choose 3 as middle element.
    - For ascending part (first < middle < last):
        - Valid first elements: 1 (i.e. 2 only)
        - Valid last elements: 1 (i.e. 4 only)
        - Total no. of pairs = valid first * valid last = 1 * 1 = 1
    - For descending part (first > middle > last):
        - Valid first elements: 1 (i.e. 5 only)
        - Valid last elements: 2 (i.e. 4, 1)
        - Total no. of pairs = valid first * valid last = 1 * 2 = 2
    - Total no. of pairs = Ascending pairs + Descending pairs = 1 + 2 = 3

- So, the problem simplifies to this:
    - For each element, choose it as middle element
    - Find number of elements less than it on left & greater than it on right
    - Multiply these 2 counts to get no. of pairs
    - SImilarly, find number of elements greater than it on left & less than it on right
    - Multiply these 2 counts to get no. of pairs
    - Add both the counts to get total no. of pairs
*/

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        for(int i = 0; i < rating.size(); i++) {
            // For ascending
            int lAsc = 0, rAsc = 0;
            for(int j = 0; j < i; j++) {
                if(rating[j] < rating[i]) lAsc++;
            }
            for(int j = i+1; j < rating.size(); j++) {
                if(rating[i] < rating[j]) rAsc++;
            }
            res += lAsc * rAsc;

            // For descending
            int lDesc = i - lAsc;
            int rDesc = rating.size() - i - 1 - rAsc;
            res += lDesc * rDesc;
        }

        return res;
    }
};