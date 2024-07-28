//You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

//note - whenever u get a problem which involve creation of a new node then use the concept of dummy node and dont use extra space to form a new linked list


 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* t1 = list1;// t1 is a ptr which stores adress of head of ll 1 ,
    ListNode* t2 = list2;//t2 is ptr which stores adress of head of ll 2
    ListNode* dummynode = new ListNode(-1);//we created a new dummynode and gave it value -1 now initialise a temp from dummy node
    ListNode* temp = dummynode;
    //now we will not create any new linked list we will directly connect the required node to temp such that resultant ll is in sorted order one by one by comparing t1 and t2 and pointing temp ka next to the ptr which has smaller value
    while(t1 != NULL && t2 != NULL){
        if(t1->val < t2->val){
            temp->next = t1;//temp ka next t1 node p point karega
            temp = t1;//or ab temp t1 node ka adress store karega , temp ko ab t1 par le aao, 
            //or t1 ptr ko move krado taaki agli baar next elem compare ho
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
        temp->next = t2;//temp k next ko t2 p point karado kyuki hm aage t2 wala node add karna chahte ll m
            temp = t2;//temp ko t2 p le aao
            t2 = t2->next;//t2 ko aage move karado
    }
       return dummynode->next;//head of sorted merged ll
    }