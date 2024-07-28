// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

// Do not modify the linked list.

ListNode* detectCycle(ListNode *head) {
        //take two pointers and initialise them with head
        ListNode* slow;
        ListNode* fast;
        slow = fast = head;
        //now start a loop where slow moves 1 step ahead and fast moves 2 step ahead; if it is a linear linked list then ye loop tab tak chlega jab tak fast 2 step ahead aage ja sakta hai,in case of linear- it will come out of loop without returning anything so return false after loop
        //floyd cycle algo: if a loop exists in linked list then slow and fast will surely meet at a point, return true and break the loop here
         bool iscycle = false;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
           
            fast = fast->next->next;
            if(slow == fast){
                iscycle = true;
                break;
            }
        }
        if(iscycle == false){
            return NULL;
        }else{
            //but if a cycle exists then to find the connection point of the loop we need to bring slow ptr to head and now , start a loop again and move each slow and fast by 1 step, the point where thwy meet is the connection point and return slow pointer the no. of steps slow pointer has taken is equal to index of node where cycle begins
            slow = head;
            if(slow == fast){
//case when slow and fast are at head, no need to run a loop means last node is connected to head , cycle begins at head
                cout<<"tail connects to node index 0";
            }
            
            while(slow != fast){
                slow = slow->next;
               
                fast = fast->next;
            }

        }
       return slow;
    };

