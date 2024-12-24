//internally array ka use ho rha jispe 2 pointers hai , front or rear pointer
//push karoge back se to rear pointer +1 hoga
//or pop karoge front se to front pointer +1 hoga

//arr ki size fixed hoti hai or ab agar, mai koi elem push karna chahti hu or rear pointer arr k end m hai to nhi kr skti kyuki rear++ to nhi ho paega, 
//agar arr k start se elem pop hue or arr k start m space khali hai to elem ko vha push karo or rear pointer ko bhi vha le jaao
// jaise hi rear arr k end p ho or ham rear++ kare to we want ko rear 0 par aa jae
//this is done using
// rear = (rear +1) %n; where n is size of arr
#include<iostream>
using namespace std;
class Queue{
  int arr[];
  int capacity;
  int currsize;
  int f,r;
public:
//constructor initialising the values
Queue(int capacity){
this->capacity = capacity;
arr = new int[capacity];
currsize = 0;
f = r =-1;
}
void push(int data){
//agar currsize = cap ho gyi iska mtlb arr fill ho gyi hai, naye elem ko push nhi kr skte
if(currsize == capacity){
  cout<<"queue is full"<<endl;
  return;
}
//rear ko next empty space par leke aao or phir us index p data enter karo
rear = (rear+1)%capacity;
arr[rear] = data;
}
void pop(){

}
}
