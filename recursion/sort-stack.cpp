#include<iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
void insertstack(stack<int> &stack, int temp){
  // you can simply insert a elem in stack without worrying about the order when stack is empty 0r the temp elem is greater than the top elem of stack
  if(stack.empty() || temp>= stack.top()){
    stack.push(temp);
    return;
  }
  // Recursive case: current is less than or equal to the top element
    int top = stack.top(); // Store the top element
    stack.pop(); // Remove the top element

    // Recursively call sortedInsert to find the correct position for current
    insertstack(stack, temp);

    // Push the previously popped element back onto the stack
    stack.push(top);
  
}
//way to pass a stack in stl stack<int> &stack
void sortstack(stack<int> &stack){
  //base condition is when the stack is empty u can simply put the elem in it and it will be sorted
  if(stack.empty()){
    return;
  }
  //now to apply recursion for smaller input hypothesis is
  //store the top pmost elem of stack in a var and apply same function for a stack of smaller size
  int temp = stack.top();
  stack.pop();
  sortstack(stack);
  insertstack(stack, temp);

}
int main(){
  stack<int> stack;
    stack.push(30);
    stack.push(20);
    stack.push(50);
    stack.push(10);
    sortstack(stack);
    
    // to print the stack run a loop which  will run jab tak stack empty nhi ho jati
    //top elem ko print karke ek-ek karke pop karte jao
    while(!stack.empty()){
      
      cout<< stack.top()<<" ";
      stack.pop();

    }
    return 0;


}
