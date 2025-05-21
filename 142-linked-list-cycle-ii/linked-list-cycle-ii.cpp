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
    ListNode *detectCycle(ListNode *head) {
       
        
        map<ListNode*, bool> mp; //  Use pointer to track nodes
        ListNode* temp = head;

        while (temp != NULL) {
            if (mp.find(temp) != mp.end()) {
                return temp; //  Cycle detected
            }
            mp[temp] = true;  //  Mark node as visited
            temp = temp->next;
        }

        return  NULL;
    }
};