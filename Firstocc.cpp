#include <iostream>
using namespace std;
//first and last occurence of an element in a sorted array.
int firstOccurence(int* arr, int size, int key){
  int s = 0; int e = size -1;
  int mid = s +(e-s)/2;
  int ans = -1;
  while( s <= e){
    if(arr[mid] == key){
      ans = mid;
      e = mid -1;
  }else if( key > arr[mid]){
    s = mid +1;
  }else if( key < arr[mid]){
    e = mid -1;

  }
  mid = s +(e-s)/2;
  
}
return ans;
} 
int LastOccurence(int* arr, int size, int key){
  int s = 0; int e = size -1;
  int mid = s +(e-s)/2;
  int lans = -1;
  while( s <= e){
    if(arr[mid] == key){
      lans = mid;
      s = mid +1;
  }else if( key > arr[mid]){
    s = mid +1;
  }else if( key < arr[mid]){
    e = mid -1;

  }
  mid = s +(e-s)/2;
  
}
return lans;
} 

int main(){
  int arr[6] = {1,4,4,6,7,9};
   int index = firstOccurence(arr, 6, 4);
  int lastindex = LastOccurence(arr, 6 , 4);
 cout<< "The first occurence of 4 is at index "<< index <<endl;
   cout<< "The last occurence of 4 is at index "<< lastindex <<endl;
  return 0;
}