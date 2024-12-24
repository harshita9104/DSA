// There is a singly-linked list head and we want to delete a node node in it.

// You are given the node to be deleted node. You will not be given access to the first node of head.

// All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

// Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

// The value of the given node should not exist in the linked list.
// The number of nodes in the linked list should decrease by one.
// All the values before node should be in the same order.
// All the values after node should be in the same order.
// Custom testing:

// For the input, you should provide the entire linked list head and the node to be given node. node should not be the last node of the list and should be an actual node in the list.
// We will build the linked list and pass the node to your function.
// The output will be the entire list after calling your function.
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        //since we dont have access to the head of ll we cant traverse thr the ll and get access to the prev node of the node to be deleted 
        //since we are only given node to be deleted we have access to it and the next node of it
        //so i will make the val of this node eq to its next node val and i will amke its next pointer point at node k next ka next 
        //since we dont have to delete a node , given in question we just bhave to remove this node from ll and dec the no. of nodes in ll
        node->val = node->next->val;//next node ki val daaldi node m
        node->next = node->next->next;//node ka next will now point to the node ek chodke aage wala next node
    }
};
