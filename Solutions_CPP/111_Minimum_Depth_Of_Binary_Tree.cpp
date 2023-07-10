// 111. Minimum Depth of Binary Tree
/* iven a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.
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
=> We can use Depth First Search to solve the problem.

=> To find the depth of the binary tree, we recursively call the function and check the following
    1. If the node is 'NULL', then we have reached the end..........Return 0
    2. If both child are not 'NULL', then we are not at a leaf node.........Return minimim length of subtree (Left or Right) + 1
    3. If the current node has only one child or no children, we return the maximum depth between the left and right subtrees plus 1. This is because in this case, we should consider the depth of the subtree that has nodes, as the other subtree is empty.
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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);
    
        if(root->left && root->right)
            return min(left+1,right+1);
        
        return max(left+1,right+1);
    }
};
