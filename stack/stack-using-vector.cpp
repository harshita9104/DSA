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

}