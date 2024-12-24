// You are given a stack St. You have to reverse the stack using recursion.

// Example 1:

// Input:
// St = {3,2,1,7,6}
// Output:
// {6,7,1,2,3}
// Explanation:
// Input stack after reversing will look like the stack in the output.
#include<iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
// Recursive Case:

// int val = St.top(); St.pop();:
// Store the top element of the stack in val and then remove it from the stack.
// insert(St, temp);:
// Recursively call insert with the remaining stack to continue pushing temp deeper into the stack.
// St.push(val);:
// After the recursion adds temp to the bottom of the stack, the previous elements (stored in val) are pushed back onto the stack in their original order.
// The insert function ensures that an element (temp) is inserted at the bottom of the stack.


void insert(stack<int> &St, int temp){
    //BC : when stack is empty we can simply insert any elm in it
    if(St.empty()){
        St.push(temp);
        return;
    }
    int val = St.top();
    St.pop();
    insert(St, temp);
    St.push(val);
    }
    // Base Case:

// if (St.size() == 1) { ... }:
// If the size of the stack is 1, it is already reversed, so no action is needed.
// This is the stopping condition for the recursion.
// Recursive Case:

// int temp = St.top(); St.pop();:
// Store the top element of the stack in temp and then remove it from the stack.
// Reverse(St);:
// Recursively call Reverse to reverse the remaining elements in the stack.
// insert(St, temp);:
// After reversing the remaining stack, use the insert function to place the stored element (temp) at the bottom of the stack.

    void Reverse(stack<int> &St){
        //BC : when size of stack is 1 no need to do anything it is reversed
        if(St.size() == 1){
            return;
        }
        int temp = St.top();
        St.pop();
        Reverse(St);
        insert(St, temp);
    }