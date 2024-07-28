// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]
 


int getsize(ListNode* head){
        ListNode* temp = head;
        int sz = 0;
        while(temp != NULL){
            temp = temp->next;
            sz++;
        }
        return sz;

    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getsize(head);
        ListNode* prev = head;
        //mistack handle the edge case when n is eq to size of ll then we have to delete the head of ll and get newhead
        // If n is equal to the size of the list, we need to remove the head
        if (n == size) {
            ListNode* newHead = head->next;
            delete head;  // Free the memory of the old head
            return newHead;
        }
        if(size == 1){
            return NULL;
        }

        // we need to bring temp at prev index to the node we want to delete 
        //and then make prev ka next point at prev->next->next
        //observations piche se nth node is aage se size-n+1
        //and its prev node will be (size-n)th node so run a loop to reach at prev node 
        //initially prev head p h 
        //mistake i ko 1 se shuru karo
        for(int i = 1; i< size-n; i++){
            prev = prev->next;

        }
        //make the temp ka next point to nth node k aage wala node
        ListNode* todel = prev->next;
        //mistake check that it doesnt point to null ptr
  if (todel != nullptr) {
            prev->next = todel->next;
            delete todel;  // Free the memory of the deleted node
        }

        // Free the memory of the deleted node

        return head;
    }