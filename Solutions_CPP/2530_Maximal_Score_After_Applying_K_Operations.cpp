// 2530 : Maximal Score After Applying K Operations

/*
You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.
In one operation:

choose an index i such that 0 <= i < nums.length,
increase your score by nums[i], and
replace nums[i] with ceil(nums[i] / 3).

Return the maximum possible score you can attain after applying exactly k operations.
The ceiling function ceil(val) is the least integer greater than or equal to val.
 

*/

/*
Example 1:

Input: nums = [10,10,10,10,10], k = 5
Output: 50
Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.

Example 2:

Input: nums = [1,10,3,3,3], k = 3
Output: 17
Explanation: You can do the following operations:
Operation 1: Select i = 1, so nums becomes [1,4,3,3,3]. Your score increases by 10.
Operation 2: Select i = 1, so nums becomes [1,2,3,3,3]. Your score increases by 4.
Operation 3: Select i = 2, so nums becomes [1,1,1,3,3]. Your score increases by 3.
The final score is 10 + 4 + 3 = 17.

 

*/

/*
Constraints:

1 <= nums.length, k <= 105
1 <= nums[i] <= 109


*/

/*
- This can be solved using Max Heap
- For each iteration, we get the top most element from the max heap, add it to the score & replce it with the new value i.e. ceil( max_number / 3 )
- Continue this operation for k times
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