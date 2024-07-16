//Function to delete middle element of a stack.
//Base Case:

// if (n == m): This checks if the current element is the middle element.
// When n (the current size of the stack in the recursion) equals m (the middle index), it means we have reached the middle element of the stack.
// s.pop();: Remove the middle element.
// return;: Exit the function since the middle element has been removed.
// Recursive Case:

// int a = s.top();: Save the current top element of the stack.
// s.pop();: Remove the top element to move towards the middle element.
// solve(s, n - 1, m);: Recursively call solve with n - 1 to continue processing the next element in the stack.
// s.push(a);: After the middle element has been removed and we return from the recursion, push the stored element back onto the stack to restore the stack’s order (minus the middle element).
#include <bits/stdc++.h>
#include <stack>
using namespace std;
     void solve(stack<int>&s , int n, int m){
        if(n == m){
            s.pop();
            return;
        }
        int a = s.top();
                s.pop();
                solve(s, n-1, m);
            s.push(a);
    }
    
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
      // This calculates the middle index m. The expression (sizeOfStack + 1) / 2 ensures that the middle element is correctly identified.
// For instance, if sizeOfStack is 5 (odd number), m will be 3 (the middle element). If sizeOfStack is 4 (even number), m will be 2 (the first of the two middle elements
        int m = (sizeOfStack+1)/2;
        int n = sizeOfStack;
        solve(s, n, m);
    }
