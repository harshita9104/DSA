//implementing stack means implementing all the operations such as push, pop, top  in O(1)
//internally memory m arr hoga, but vo behave krega stack ki tarah
//LIFO property should be maintained, internally arr is used, and your class object will act as a stack

#include<iostream>
#include<bits/stdc++.h>
using namespace std; 
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};


void MyStack ::push(int x) {
    // Your Code
   if(top < 999){
        top ++;
        arr[top] = x;
    }

}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    // Your Code
    
        if( top >= 0){
        int x = arr[top];
        top--;
        return x;
    }
    else{
        return -1;
    }

};
//stack ko arr se implement krne k liye phle arr ki size define krnhi pdti hai,
//vector m size initially btane ki jarurt nhi h, vector dynamically work karte hai
//stack ko, uski sari functionalities ko vector m implement kr rhe, LIFO prop maintain krte hue


class Stack {
    vector<int> v;
public:
    // When the object of Stack class calls push function, we will push_back the value in vector
    void push(int val) { // O(1)
        v.push_back(val);
    }

    void pop() { // O(1)
        if (isEmpty()) {
            return;
        }
        v.pop_back();
    }

    int top() { // O(1)
        if (isEmpty()) {
            return -1;
        } else {
            return v[v.size() - 1];
        }
    }

    bool isEmpty() {
        return v.empty();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.isEmpty()) {
        cout << s.top() << endl;
        s.pop(); // pop the top element to avoid infinite loop
    }

    return 0;
}
