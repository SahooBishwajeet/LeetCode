// 137. Single Number II
/* Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

/*
Example 1:
Input: nums = [2,2,3,2]
Output: 3

Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99

Constraints:
1.1 <= nums.length <= 3 * 104
2. -231 <= nums[i] <= 231 - 1
3. Each element in nums appears exactly three times except for one element which appears once.
*/

/*
=> Using Bit Manipulation to solve the problem

=> 'ones' variable store number of times a number has occured 1 time and 'twos' will store number of times a number has ocured 2 times. 
=> We use XOR and AND operation to update everytime we get a number once, twice (when we get a number twice, we need to remove from 'ones' and add it to 'twos') and thrice (when we get a number thrice, we need to remove from 'twos')
=> 
=> In the ned, 'ones' will be storing the number which has occured 1 time.
*/
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ones = 0;
    int twos = 0;

    for (const int num : nums) {
      ones ^= (num & ~twos);
      twos ^= (num & ~ones);
    }

    return ones;
  }
};
