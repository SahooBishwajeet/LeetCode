// 2583 : Kth Largest Sum in a Binary Tree

/*
You are given the root of a binary tree and a positive integer k.
The level sum in the tree is the sum of the values of the nodes that are on the same level.
Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
Note that two nodes are on the same level if they have the same distance from the root.
 

*/

/*
Example 1:


Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.

Example 2:


Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.

 

*/

/*
Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= 106
1 <= k <= n


*/

/*
- We can solve the problem by using Level Order Traversal.
- to do this, we will use a queue to store the nodes of the tree, which will be iterated in a loop.

- For each level, we store the value of the sum in a priority queue.
- After we have traversed all the levels, we simply pop the top element from the priority queue k times to get the kth largest level sum.
- If there are less than k elements in the priority queue, we return -1, as asked in the problem statement.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> pq;

        queue<TreeNode*> bfsQ;
        bfsQ.push(root);

        while(!bfsQ.empty()) {
            long long size = bfsQ.size();
            long long currSum = 0;
            for(int i = 0; i < size; i++) {
                TreeNode* popNode = bfsQ.front();
                bfsQ.pop();

                currSum+=popNode->val;

                if(popNode->left != nullptr) {
                    bfsQ.push(popNode->left);
                }

                if(popNode->right != nullptr) {
                    bfsQ.push(popNode->right);
                }
            }
            pq.push(currSum);
        }

        if(pq.size() < k) return -1;
        while(k-- > 1) {
            pq.pop();
        }
        return pq.top();
    }
};