// 229. Majority Element II
/* Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
*/

/*
Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]
 
Constraints:
1. 1 <= nums.length <= 5 * 104
1. -109 <= nums[i] <= 109
*/

/*
=> Using Hashing to solve the problem

=> We simply store the frequency of each elements and store all the elements having more than the required Limit/Threshold
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int limit = nums.size() / 3;
        unordered_map<int, int> mp;
        vector<int> result;

        for(int i:nums)
            mp[i]++;
        
        for(auto i:mp)
            if(i.second > limit)
                result.push_back(i.first);

        return result;
    }
};
