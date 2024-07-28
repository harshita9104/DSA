ListNode* reverseList(ListNode* head) {
        //we will consider a small portion of linked list first prev, curr, and next node we will reverse the connection of prev and current, by making curr->next point at prev and update their values by shifting them one step ahead, this loop will continue jab tak curr null ko point nhi karta
        ListNode* prev = NULL;
        ListNode* curr = head;
      

        while(curr != NULL){
            //as everytime curr gets updated next also need to be updated 
            //and before reversing the connection of initial prev and curr node we need to save curr->next in a pointer
            ListNode* next = curr->next;
            curr->next = prev;//connection is reversed
//now update prev first and then curr
prev = curr;
curr = next;

        }
        //since we are out of while loop curr is pointing to null so last node is prev which becomes our head now
        head = prev;
        
return head;
    }