// 86. Partition List
/* Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
*/

/*
Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:
Input: head = [2,1], x = 2
Output: [1,2]
 
Constraints:
1. The number of nodes in the list is in the range [0, 200].
2. -100 <= Node.val <= 100
3. -200 <= x <= 200
*/

/*
=> We can use 2 Pointer (Dummy) to solve the problem.
=> One will store all the Nodes less than Key & another will store all the Nodes greater than or equal to Key.

=> Traverse the list and add the nodes accordingly to beforeCurr & afterCurr pointer.
=> After traversing the whole list merge the 2 lists.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode before(0), after(0);
        ListNode * beforeCurr = &before; 
        ListNode * afterCurr = &after;

        while(head){
            if(head->val < x){
                beforeCurr->next = head;
                beforeCurr = head;
            }
            else{
                afterCurr->next = head;
                afterCurr = head;
            }
            head = head->next;
        }

        afterCurr->next = nullptr;
        beforeCurr->next = after.next;

        return before.next;
    }
};
