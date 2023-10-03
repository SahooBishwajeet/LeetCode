// 1512 Number Of Good Pairs
/*Given an array of integers nums, return the number of good pairs.
A pair (i, j) is called good if nums[i] == nums[j] and i < j.
*/

/*
Example 1:
Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

Example 2:
Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.

Example 3:
Input: nums = [1,2,3]
Output: 0
 
Constraints:
1. 1 <= nums.length <= 100
2. 1 <= nums[i] <= 100
*/

/*
=> We use Unordered_Maps to solve this problem

=> We will intiliaze ans with 0 and an empty unordered map to store the occurrence of the element
=> For each element in the given array:
      if element/number is present in the map that means for example at any time in unordered map we saw count of num(element) 1 is 2 thats means currunt element can form 2 pair with previous 1, so at that time we will add this count in answer and also increase the count of the element in out map
      if element/number is not present in the map, it means this is the first time we're seeing this number, so we initialize its count to 1.

=> At last we will return our answer
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int answer = 0;
        unordered_map<int, int> count;

        for(int i : nums)
            answer += count[i]++;
        
        return answer;
    }
};
