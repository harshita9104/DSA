//push in queue means push_back in ll
//pop in queue means pop_front in ll
//front in queue is head->data in ll
/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x)
{//internally we are pushing elem in a ll from back
        QueueNode* newnode = new QueueNode(x);//create a new node
        if(front == NULL){
            front = rear = newnode;//if queue was initially empty then new front and rear node becomes the new node
        }else{
            rear->next = newnode;
            rear = newnode;//new tail of ll becomes the newnode
        }
        
        
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(front == NULL){
        return -1;
    }
    if(front == rear){
        int data = front->data;
        front = rear = NULL;
        return data;
    }else{
        int temp = front->data;
    QueueNode *todel = front;
    front = front->next;
    // if (!front) rear = nullptr; 
    delete todel; 
    return temp;
    }
        
}
