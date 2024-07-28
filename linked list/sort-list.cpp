//leetcode -148
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* t1 = list1;// t1 is a ptr which stores adress of head of ll 1 ,
    ListNode* t2 = list2;//t2 is ptr which stores adress of head of ll 2
    ListNode* dummynode = new ListNode(-1);//we created a new dummynode and gave it value -1 now initialise a temp from dummy node
    ListNode* temp = dummynode;
    //now we will not create any new linked list we will directly connect the required node to temp such that resultant ll is in sorted order one by one by comparing t1 and t2 and pointing temp ka next to the ptr which has smaller value
    while(t1 != NULL && t2 != NULL){
        if(t1->val < t2->val){
            temp->next = t1;//temp ka next t1 node p point karega
            temp = t1;//or ab temp t1 node ka adress store karega , temp ab t1 p aa jaega, or t1 ptr ko move krado taaki agli baar next elem compare ho
            t1 = t1->next;

        }else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }//is loop se bahar aaya mtlb t1 ya t2 m se koi exhaust ho gya 
    while(t1 != NULL){
         temp->next = t1;//temp ka next t1 node p point karega
            temp = t1;//or ab temp t1 node ka adress store karega , temp ab t1 p aa jaega, or t1 ptr ko move krado taaki agli baar next elem compare ho
            t1 = t1->next;
    }
    while(t2 != NULL){
        temp->next = t2;
            temp = t2;
            t2 = t2->next;
    }
       return dummynode->next;
    };
    ListNode* SplitAtMid(ListNode* head){
        //ll ko mid point p split kar skte hai by 2 pointer method
        //take slow and fast pointer starting from head and slow+1 and fast+2
        //when slow will reach end of ll slow will be at mid of ll
        //slow will be the righthead (head of right portion)
        //and track the prev to slow to break the connection at mid
        //mistake- to handle the case when only one elm in ll
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        //mistake not eq to sign shd be used and && operator, koi ek bhhi condition false hui loop se bahar aa nikal jaega
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }//when this loop ends i.e; fast is at end or null, slow will be at mid and prev will be at the point where connection has to break
        //mistake ensure the prev is still not null
        if (prev != nullptr) {
        prev->next = nullptr;
    }
        return slow;//righthead 
    };
    ListNode* sortList(ListNode* head) {
        //if only one elem in ll then we cant split it
        //mistake- use of OR operator instead of & , kyuki dono case sath m true nhi ho skte
        // Base case: if the list is empty or contains only one element
        if(head == NULL || head->next == NULL){
            return head;//as it is already sorted
        }
     ListNode* righthead = SplitAtMid(head);//head of right portion(unsorted)
        ListNode* left = sortList(head);//recursive call to sort left portion
        ListNode* right = sortList(righthead);//recursive call to sort right portion, since a ll is identified by its head we pass the head of right portion, left and right parts are sorted now merge them, pass the head of sorted left and right portion 
    return mergeTwoLists(left, right);
        
    }