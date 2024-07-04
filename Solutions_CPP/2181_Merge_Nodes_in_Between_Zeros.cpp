// 2181 : Merge Nodes in Between Zeros

/*
You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.
For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.
Return the head of the modified linked list.
 

*/

/*
Example 1:


Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.

Example 2:


Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.

 

*/

/*
Constraints:

The number of nodes in the list is in the range [3, 2 * 105].
0 <= Node.val <= 1000
There are no two consecutive nodes with Node.val == 0.
The beginning and end of the linked list have Node.val == 0.


*/

/*
=> We can simply use simulation to solve the problem.

=> As we want to do this inplace, we need a pointer node for the head of the list.
=> The "nextSum" pointer will iterate through the list & perform the following:
  - It will calculate the sum of all the nodes until it reaches a zero.
  - It will update the value of the head pointer to the sum calculated.
  - And update itself to the next node.
=> Now we need to delete the intermediate nodes between the head & the next zero.
=> We can do this by updating the next pointer of the head to the next pointer of the next zero, which is currently pointed by the "nextSum" pointer.

=> Return the head pointer.
=> Time complexity: O(N), where N is the number of nodes in the list. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newList = head->next;
        ListNode* nextSum = head->next;

        while(nextSum) {
            int sum = 0;

            while(nextSum->val != 0) {
                sum += nextSum->val;
                nextSum = nextSum->next;
            }
            newList->val = sum;
            nextSum = nextSum->next;
            
            newList->next = nextSum;
            newList = newList->next;
        }

        return head->next;
    }
};