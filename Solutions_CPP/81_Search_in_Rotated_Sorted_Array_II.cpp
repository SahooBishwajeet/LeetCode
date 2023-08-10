// 88. Search in Rotated Sorted Array II
/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array
is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
You must decrease the overall operation steps as much as possible.
*/

/*
Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

Constraints:
1. 1 <= nums.length <= 5000
2. -104 <= nums[i] <= 104
3. nums is guaranteed to be rotated at some pivot.
4. -104 <= target <= 104
*/

/*
=> We use Binary Search (With a bit of modification) to solve the problem.
=> The modification is to identify the sorted half of the Array. (This is the most crucial part of this approach)

=> If left half [left...mid] is sorted: We know this if num[left] is less than or equal to num[mid]. In a normally sorted array, if the start is less than or equal to the midpoint, it means all elements till the midpoint are in the correct increasing order.
      If the target lies within this sorted left half: We know this if the target is greater than or equal to num[left] and less than num[mid]. If this is the case, we then move our search to this half.
      Else : The target must be in the right half. So, we move our search to this half instead.
=> If right half [mid...high] is sorted: If the left half isn't sorted, the right half must be!
      If the target lies within this sorted right half: We know this if the target is greater than num[mid] and less than or equal to num[right]. If so, we move our search to this half.
      Else: The target must be in the left half. So, we move our search to this half instead.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while(left <= right){
            int mid = (left + right)/2;

            if(nums[mid] == target) return true;

            if(nums[left] == nums[mid]){
                left++;
                continue;
            }

            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            else{
                if(nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }

        return false;
    }
};
