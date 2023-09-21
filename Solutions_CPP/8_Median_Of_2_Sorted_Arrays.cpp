// 8. Median Of 2 Sorted Arrays
/* 
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
*/

/*
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 2

Example 2:
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 
Constraints:
1. The number of nodes in the tree is in the range [0, 105].
2. -1000 <= Node.val <= 1000
*/

/*
=> We can simply store the sorted values one by one in another array and get the median from the merged array
=> Median can be found based on the length of the Merged array i.e. Mid for odd number of elements & [Mid + (Mid - 1)] / 2 for even number of elements
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArray;
        int i = 0, j = 0;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j])
                mergedArray.push_back(nums1[i++]);
            else
                mergedArray.push_back(nums2[j++]);
        }

        while(i < nums1.size()) mergedArray.push_back(nums1[i++]); 
        while(j < nums2.size()) mergedArray.push_back(nums2[j++]);

        int mid = mergedArray.size() / 2;
        if(mergedArray.size() % 2 == 0)
            return (mergedArray[mid] + mergedArray[mid - 1]) / 2.0;
        else
            return mergedArray[mid]; 
    }
};
