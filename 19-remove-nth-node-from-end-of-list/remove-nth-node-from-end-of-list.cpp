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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 1;
        while(temp->next != NULL){
           temp = temp->next;
           count++;
        }
        int num = count - n;
        if(num == 0){
            if(head->next == NULL){
               return NULL;
            }else{
                return head->next;
            }
           
        }
        ListNode* curr = head;
        for(int i = 1; i< num; i++){
           curr= curr->next;

        }
        if(curr->next->next != NULL){
           curr->next = curr->next->next;
        }else{
            curr->next = NULL;
        }
        
        return head;
    }
};