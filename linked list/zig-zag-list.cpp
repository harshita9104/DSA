//  You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes.
//leetcode 148
 ListNode* SplitAtMid(ListNode* head){
       ListNode* slow = head;
       ListNode* fast = head;
       ListNode* prev = NULL;//for the cases where ll has no elem or only one elem
       while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
       } //as no split is possible when ll has only 1 elem
       if(prev != NULL){
        prev->next = NULL;
       }
       return slow;//righthead
    };
    ListNode*  reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        if(curr->next == NULL){
            return head;
        }
        while(curr != NULL){
            ListNode* next = curr->next;//curr ka next se connection todne se phle next ko store karlo
            curr->next = prev;
            //update prev and curr by moving one step ahead
            prev = curr;
            curr= next;
        }//since prev ios at last node , prev is new head
        head = prev;
        return head;

    };
    void reorderList(ListNode* head) {
        //1st split the ll in two parts
        //reverse the second part
        ListNode* righthead = SplitAtMid(head);
        ListNode* rightheadrev = reverse(righthead);
        //do alternate merging
        // ListNode* dummynode = new ListNode(-1);
        ListNode* left = head;
        ListNode* right = rightheadrev;
        ListNode* tail = right;
        // left = dummynode->next;
        //without using extra space hm bas connections ko change karenge
        // (left portion ka head)left ko (reversed right portion ka head) right se connect karenge , phir right ko left k next node se connect karenge phir left k next ko right k next se connect karenge in a loop 
        while(left != NULL && right != NULL){
            //left k next or right k next ko store karlo kyuki unse jab left or right ka connection break hoga to phir ye lost ho jaenge
            ListNode* leftnext = left->next;
            ListNode* rightnext = right->next;
            //change the connections
            left->next = right;
            right->next = leftnext;
            tail = right;//to keep track of right for a special case
            //update the left and right pointers
            left = leftnext;
            right = rightnext;

        }
        //in case of odd elem in ll , the second portion has 1 more elem than left portion and the last elem is remaining to be added to final ll that's why we were tracking right pointer with tail node
        if(right != NULL){
            tail->next = right;
        }
        // return dummynode->next;
    }