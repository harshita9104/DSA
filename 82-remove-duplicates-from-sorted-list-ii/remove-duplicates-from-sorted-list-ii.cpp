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
        // Handle edge cases where the list is empty or has only one node
        if (head == NULL || head->next == NULL) {
            return head;  // No duplicates to remove, return the list as is
        }
        //brute force app is  start from head iterating over elements maintain a map storimg count of elem occuring in ll , next step iterate over map and pick all elem with count 1 , and then return a new list with no duplicates , extra space of map is used 
        //in this problem sorted is imp to solve , which gives us advantage , that all the duplicates will be adjacent to each other, so u can simply skip these adj duplicates elem by just iterating over the list
        
        //in this question the problem will arise when the node u are standing at needs to be deleted
        //in such problems dummy node comes handy which is arbitrary node with random val pointing at head , 
        ListNode* dummy = new ListNode(0, head);
        //val is 0 and pointinga t head at the end of this problem to return the new ll we will return dummy ka next which is head of new ll 
        //for this take help of 2 pointers prev and curr , prev will be pointing at last unique node and we will iterate over ll using curr node 
        ListNode* prev = dummy;//initialise prev at dummy
        ListNode* curr = head;
        //check if the val of curr node is same as the val of next node run a while loop and skip all these duplicates
        while(curr != NULL){
            if(curr->next != NULL && curr->val == curr->next->val){
                while(curr->next != NULL && curr->val == curr->next->val){
                 curr = curr->next;
                }
                
            
             //and this loop will stop at the last duplicate node so after the loop make prev ka next point at curr(last duplicate) ka next this way all duplicates are removed 
            prev->next = curr->next;//prev vahi hai jha phle tha bas uska next ab last duplicate k baad jo unique elem mila h usko point kr rha 
            }else{
            //or agar koi duplicate nhi hai to prev ko curr p point krwado kyuki hmara curr unique elem h
            prev = curr;
        }
        //loop chlane k liye next p bhejo curr ko
        curr = curr->next;
        
       


    }
    return dummy->next;
    }
};