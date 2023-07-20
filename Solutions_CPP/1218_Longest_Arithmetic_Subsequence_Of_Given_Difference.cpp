// 1218. Longest Arithmetic Subsequence of Given Difference
/* Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.
*/

/*
Example 1:
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].

Example 2:
Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.

Example 3:
Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
 
Constraints:
1. 1 <= arr.length <= 105
2. -104 <= arr[i], difference <= 104
*/

/*
=> We use Hash Maps to solve the problem.

=> Iterate over each element in the input vector arr using a for loop.
=> For each element c at index i, check if there is an element c-difference present in the map m. This is done using the find function of the unordered map.

=> If c-difference is found in the map, update the frequency of the current element c in the map mp by incrementing the frequency of c-difference by 1 and assign it to mp[c].
=> If c-difference is not found in the map, assign 1 to mp[c] as it is the first occurrence of c with the given difference.

=> Update the maximum length if necessary.
*/
*/
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int>mp;
        int maximum = 0, len = arr.size();

        for(int i = 0; i < len; i++){
            int c = arr[i];
            
            if(mp.find(c - difference) != mp.end())
                mp[c] = mp[c - difference] + 1;
            else
                mp[c]=1;
            
            maximum = max(maximum,mp[c]);
        }
        return maximum;
    }
};
