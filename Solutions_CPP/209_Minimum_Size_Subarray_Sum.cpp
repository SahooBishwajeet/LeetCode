// 209. Minimum Size Subarray Sum
/* Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
*/

/*
Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 
Constraints:
1. 1 <= target <= 109
2. 1 <= nums.length <= 105
3. 1 <= nums[i] <= 104
*/

/*
=> Using Sliding window to solve the problem
=> Maintain 2 pointers to determine size of window. Move the right pointer 1 step in each iteration
=> Move the left pointer to right 1 place until we get the condition satisfied (sum == target)
=> Store length of subarray in a variable and update if size of new subarray is less than previous one

=> Initially we have taken size of subarray as INT_MAXX.......If we don't get a single subarray satisfying the condition then INT_MAX is unchanged, so return statement is a conditional
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, sum = 0, minLen = INT_MAX;
        int size = nums.size();
        while(j < size){
            sum += nums[j];
            
            while(sum >= target){
                sum -= nums[i];
                minLen = min(j - i + 1, minLen);
                i++;
            }
            j++;
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};
