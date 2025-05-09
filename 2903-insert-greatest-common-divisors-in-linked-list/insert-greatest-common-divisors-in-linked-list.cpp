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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
    
    //set two pointers and then run a while loop until second node pointer becomes null as we have to insert gcd node bw two nodes
    //initialising the pointer
    ListNode* node1 = head;
    ListNode* node2 = head->next;
    while(node2 != NULL){
        int val = gcd(node1->val, node2->val);
        ListNode* newnode = new ListNode(val);
        node1->next = newnode;
        newnode->next = node2;
        node1 = newnode->next;
        node2 = node1->next;
    }

    return head;
    
    }
    private:
    int gcd(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }  
};