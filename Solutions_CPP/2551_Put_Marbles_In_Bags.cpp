// 2551. Put Marbles in Bags
/* You have k bags. You are given a 0-indexed integer array weights where weights[i] is the weight of the ith marble. You are also given the integer k.

Divide the marbles into the k bags according to the following rules:
1. No bag is empty.
2. If the ith marble and jth marble are in a bag, then all marbles with an index between the ith and jth indices should also be in that same bag.
3. If a bag consists of all the marbles with an index from i to j inclusively, then the cost of the bag is weights[i] + weights[j].
The score after distributing the marbles is the sum of the costs of all the k bags.

Return the difference between the maximum and minimum scores among marble distributions.
*/

/*
Example 1:
Input: weights = [1,3,5,1], k = 2
Output: 4
Explanation: 
The distribution [1],[3,5,1] results in the minimal score of (1+1) + (3+1) = 6. 
The distribution [1,3],[5,1], results in the maximal score of (1+3) + (5+1) = 10. 
Thus, we return their difference 10 - 6 = 4.

Example 2:
Input: weights = [1, 3], k = 2
Output: 0
Explanation: The only distribution possible is [1],[3]. 
Since both the maximal and minimal score are the same, we return 0.

Constraints:
1. 1 <= k <= weights.length <= 105
2. 1 <= weights[i] <= 109
*/

/*
=> Observation :- No matter what partition we make, we always end up adding the adjacent elements of the partition (Plus First & Last element).
=> So the approach would be to get sum of all adjacent elements and get MAX and MIN sum.

=> In an array, store sum of adjacent elements and sort it.
=> Now take first 'k - 1' elements, which would give the minimum score, and last 'k - 1' elements, which would give the maximum score
[To make 'k' partitions, we need to draw 'k - 1' lines].
*/
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int len = weights.size();
        if(k == 1 || k == len) return 0;

        vector<int> answer;
        for(int i = 1; i < len; i++)
            answer.push_back(weights[i - 1]+weights[i]);
        
        sort(answer.begin(), answer.end());
        long long min = 0, max = 0;

        for(int i = 0; i < k - 1; i++){
            min += answer[i];
            max += answer[len - 2 - i];
        }

        return max - min;
    }
};
