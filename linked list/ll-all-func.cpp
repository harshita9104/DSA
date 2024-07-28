#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//form a node and a list class which can be used in main func to create  a linked list
class Node{
  public:
  int data;
  Node* next;
  Node(int val){
    data = val;
    next = NULL;
  }
};
class linkedlist{
  public:
  Node* head;
  Node* tail;
  linkedlist(){
    head = NULL;
    tail = NULL;
  }
  void push_back(int val){
    //create a new node dynamically
    Node* new_node = new Node(val);//so we created a memory in heap for our new node an a pointer called new_node points to this memory , new_node stores the adress of this memory
    //two cases : 1 if ll is empty then head and tail would point to this new node now
    if(head == NULL){
      head = tail = new_node;//head and tail ptr now containes the adress of new node that is they point to new node now
    }else{
      //when ll already has elements
      //to push back new node the tail ka next shd point towards new node
      tail->next = new_node;
      //update tail now
      tail = new_node;
    }
  }
    void push_front(int val){
    //create a new node dynamically
    Node* new_node = new Node(val);//so we created a memory in heap for our new node an a pointer called new_node points to this memory , new_node stores the adress of this memory
    //two cases : 1 if ll is empty then head and tail would point to this new node now
    if(head == NULL){
      head = tail = new_node;//head and tail ptr now containes the adress of new node that is they point to new node now
    }else{
      //when ll already has elements
new_node-> next = head;
head = new_node;      
    }

  }
  //function to check a loop in ll
  bool iscycle(Node* head){
    //take two pointer (initially pointing at head),slow and fast and move them with 1 step and 2 steps respectively
    //if a loop exits in ll, then the two pointers will surely meet, 
    //and if it is a linear ll, then loop tab tak chlega tab tak fast ptr 2 step aage jaa skta hai
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL ){
      //move slow by 1 step
      slow = slow->next;
      //move fast by 2 step
      fast = fast->next->next;
          //if fast and loop meet, then a loop exist in ll
    if(slow == fast){
      cout<<"cycle exists";
      return true;
    }

    }
    //if the loop ends without returning true it means either fast is pointing null or its next ptr, it means ll is linear no loop exists
    return false;
  }
};
//function to remove a cycle
int main(){
  //list class ka object banalo ll
  linkedlist ll;
  ll.push_front(4);
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);
//now to form a cycle
ll.tail->next = ll.head;
//1->2->3->4->1
ll.iscycle(ll.head);
return 0;

}