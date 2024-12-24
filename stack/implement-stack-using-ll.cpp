//in stack all the operations such as push, pop, top are done in O(1)
//stack ka push is linked list ka push at front
//jo recently push at front kiya linked list m usse head banado
//pop operation pop from front karo linked list se
// and top will return linked list k head ka data
#include<bits/stdc++.h>
using namespace std;
class StackNode {
  public:
    int data;
    StackNode* next;

    StackNode(int x) {
        data = x;
        next = NULL;
    }
};
// Check if Stack is Empty: if(top == NULL) return -1; - If the stack is empty (i.e., top is NULL), return -1.
// Retrieve the Top Value: int topData = top->data; - Store the value of the top node in topData.
// Temporary Node: StackNode* temp = top; - Store the current top node in a temporary pointer temp.
// Update the Top Pointer: top = top->next; - Move the top pointer to the next node in the stack.
// Delete the Old Top Node: delete temp; - Delete the node that was previously at the top of the stack.
// Return the Top Value: return topData; - Return the value of the removed top node.

class Stack{
  private:
  StackNode* top;//a node pointer in ll which is pointing to the top of the imaginary stack
  public:
  void push(int val){
    StackNode* newnode = new StackNode(val);//created a new node with val dynamically
    //since we need to push this newnode elem in front of ll so the next pointer of this newnode shd point at current top
    newnode->next = top;
    //and now top (which points to the head of ll) becomes the newly added node 
    top = newnode;
  }
  int pop(){//function to pop elem from top of stack , to remove from front of ll and return its value
  if(top == NULL){
    return -1;
  }
     int topdata = top->data;//store this to return in end
     StackNode* temp = top;//since i have to delete top so temporarily store it 
     
     top = top->next;//now since front elem will be deleted so the top becomes next node of the deleted node
     delete temp;
     return topdata;

  }
  bool isEmpty() {
        if(top == NULL){
          return true;
        }else{
          return false;
        }
    }
  stack(){
    top = NULL;//constructer to initialise that top pointer points to null, indicating stack is empty
  }

};
int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.isEmpty()) {
        
      cout<< s.pop()<<endl; // pop the top element to avoid infinite loop
    }

    return 0;
}

