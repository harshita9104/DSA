The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
void MyQueue :: push(int x)
{
    arr[rear] = x;//kyuki push is done from back so rear end p elem x ko daaldo 
    rear ++;//or rear ab +1 ho jaega
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
    if(front >= rear){
        return -1;//kyuki pop m ham front ko ++ kar rhe to agar vo rear k aage nikal gya to -1 return karo
    } 
    int ans = arr[front];
    front++;//pop karne p front +1 ho jaega
    return ans;
}