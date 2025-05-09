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
    ListNode* deleteDuplicates(ListNode* head) {
        //mistake - i cant check head ka next is null before checking head is null or not 
        //i need touse OR operator since both cond cant be true
        if(head == NULL || head->next == NULL){
            return head;
        }
       
        ListNode* temp = head;
        ListNode* temp2 = head->next;
        
        while(temp != NULL && temp2 != NULL){
            if(temp->val == temp2->val){
            temp ->next = temp2->next;
            //mistake done here - forgot below line if u are deleting a current temp2 node the u need to specify the new temp2 
            temp2 = temp->next;
            }else{//if there is no duplicate then we simply shift our pointers by one node to check another pair of nodes
            temp = temp->next;
            temp2 = temp2->next;
            }
                  
        }
        return head;

    }
};