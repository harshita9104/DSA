//Given a sorted array arr[] of size N, some elements of array are moved to either of the adjacent positions, i.e., arr[i] may be present at arr[i+1] or arr[i-1] i.e. arr[i] can only be swapped with either arr[i+1] or arr[i-1]. The task is to search for an element in this array.

// Examples : 

// Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
// Output: 2 

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int x){
  while(start<=end){
    int mid = start+(end- start)/2;
    if(arr[mid] == x){
      return mid;
    }else if(arr[mid-1] == x && mid-1>= start){
      return mid -1;
    }else if(arr[mid+1] == x && mid+1<= end){
      return mid +1;
    }
    if(arr[mid] < x){
      start = mid+2;
    }else if(arr[mid] > x){
      end = mid-2;
    }
  }
}
 // Driver Code
int main(void)
{
    int arr[] = { 3, 2, 10, 4, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    return 0;
}