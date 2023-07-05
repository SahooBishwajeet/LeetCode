// 1493. Longest Subarray of 1's After Deleting One Element
/* Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
*/

/*
Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Example 3:
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 
Constraints:
1. 1 <= nums.length <= 105
2. nums[i] is either 0 or 1.
*/

/*
=> Using Sliding-Window to solve the problem

=> Maintain a left, right pointer to control the length of window.
=> Store number of xeroes in the current window. We can have at most 1 0 in current window, so move left pointer forward to reduce number of zeroes by 1
=> Find length of current window and update if length > previous max length
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(); // The size of the input array

        int left = 0; // The left pointer of the sliding window
        int zeros = 0; // Number of zeroes encountered
        int ans = 0; // Maximum length of the subarray

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                zeros++; // Increment the count of zeroes
            }

            // Adjust the window to maintain at most one zero in the subarray
            while (zeros > 1) {
                if (nums[left] == 0) {
                    zeros--; // Decrement the count of zeroes
                }
                left++; // Move the left pointer to the right
            }

            // Calculate the length of the current subarray and update the maximum length
            ans = max(ans, right - left + 1 - zeros);
        }

        // If the entire array is the subarray, return the size minus one; otherwise, return the maximum length
        return (ans == n) ? ans - 1 : ans;
    }
};
