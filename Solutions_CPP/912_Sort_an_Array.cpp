// 912 : Sort an Array

/*
Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
 

*/

/*
Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.

 

*/

/*
Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104


*/

/*
=> We can use any sorting algorithm which has time complexity less than or equal to O(nlogn) to sort the array.
=> I'll use Counting Sort.
*/

class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int max = *max_element(nums.begin(), nums.end());
        int min = *min_element(nums.begin(), nums.end());

        vector<int> count(max - min + 1, 0);

        for (int i = 0; i < n; i++) {
            count[nums[i] - min]++;
        }

        for (int i = 1; i < count.size(); i++) {
            count[i] += count[i - 1];
        }

        vector<int> output(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            output[count[nums[i] - min] - 1] = nums[i];
            count[nums[i] - min]--;
        }
        return output;
    }
};