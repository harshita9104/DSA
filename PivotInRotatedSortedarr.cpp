//You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
//Now the array is rotated at some pivot point unknown to you.
//For example, if 'arr' = [ 1, 3, 5, 7, 8], then after rotating 'arr' at index 3, the array will be 'arr' = [7, 8, 1, 3, 5].
//Now, your task is to find the index at which ‘k’ is present in 'arr'.

#include <iostream>
using namespace std;
int getPivot(int* arr, int size){
  int s = 0;
  int e = size -1;
  int mid = s+ (e-s)/2;
  while(s<e){
    if(arr[mid]>= arr[0]){
      s = mid +1;
    }else{
      e = mid;
    }
    mid = s+ (e-s)/2;
  }
  return s;


}
int main(){
  int arr[5] = {6, 8, 2, 3, 5 };
  int pivot = getPivot(arr, 5);
  cout<<pivot;
  return 0;
}