// 962 : Maximum Width Ramp

/*
A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.
Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.
 

*/

/*
Example 1:

Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.

Example 2:

Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.

 

*/

/*
Constraints:

2 <= nums.length <= 5 * 104
0 <= nums[i] <= 5 * 104


*/

/*
- This can be solved using sliding window, but with a twist

- Since, at any given time, we slide the window from the Left side if the window is invalid, it is possible that a global maxima is diselected in the beginning itself
- For example, 6 0 8 2 1 6 : The window [6 0] is discarded from the start, evenn though it will give the maximum width in the end with [6 0 8 2 1 6]

- So, to solve this issue we create an array which will store, at any given index, the element which is max to the right of it
- By doing this, we will know whether to dicard the current window (if it is invalid) or not i.e. whether it has the POTENTIAL to provide a better solution in the future
*/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> mxRight(n, 0);
        int prev_max = 0;
        int i = n-1;

        for(int j = n-1; j >=0; j--) {
            mxRight[j] = max(nums[j], prev_max);
            prev_max = mxRight[j];
        }

        int res = 0, l = 0;
        for(int r = 0; r < n; r++) {
            while(l < r && nums[l] > mxRight[r]) {
                l++;
            }
            res = max(res, r-l);
        }

        return res;
    }
};