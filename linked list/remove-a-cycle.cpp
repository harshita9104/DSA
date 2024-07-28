//Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
         //take two pointers and initialise them with head
        Node* slow;
        Node* fast;
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
            return ;
        }else{
            //but if a cycle exists then to find the connection point of the loop we need to bring slow ptr to head and now , start a loop again and move each slow and fast by 1 step, the point where thwy meet is the connection point and return slow pointer the no. of steps slow pointer has taken is equal to index of node where cycle begins
            slow = head;
            if(slow == fast){
//case when slow and fast are at head,then move only fast and the moment it reaches the last node of ll break the connection
            while(fast->next != slow){
              fast = fast->next;
            }
            //remove the connection fast has reached last node
             fast->next = NULL;
            }else{
                Node* prev = fast;
            while(slow != fast){
                slow = slow->next;
               prev = fast;
                fast = fast->next;
            }
            //now prev points to the last node of the ll which is connecting the ll in a loop so if we make its next ptr null then the connection will break
            prev->next = NULL;
            
            }
            

        }
      
    }