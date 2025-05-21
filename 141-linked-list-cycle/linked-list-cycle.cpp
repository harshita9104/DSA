/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //we can also do it with 2 pointers slow and fast both starting from head slow will move one step and fast will move 2 step if at some point both will be at same position it means there is a cycle in linked list
        if(head == NULL || head->next == NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            if(slow->next != NULL){
                slow = slow->next;
            }
            if(fast->next != NULL){
            ListNode* nextnode = fast->next;
            fast = nextnode->next;
            }
            
            if(slow == fast){
                return true;
                break;
            }
        }
        return false;
    }
};