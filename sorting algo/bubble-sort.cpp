//in this sorting algo, initially apply bubble sort from 0 to n-2, as last elem is n-1, and we are checking each elem at an index , with the index ahead of it,  if (arr[i+1]>arr[i]) then we swap them this way in one iteration we willbe able to move the largest elem in last 
//since the last elem has reached its correct position now apply bubble sort , on 0 to n-3; so everytime the inner loop run from 0 to n-i-1 (observation) 
// optimised - if the arr is already sorted then no need to run the loop again & again check that it is sorted or not in one iteration as in initial iteration we got to know that no swap took place as the arr was already sorted so we can break the loop from there only
#include<iostream>
using namespace std;
void bubblesort(int arr[], int n){
  for(int i = 0; i<n-1; i++){
    bool isswap = false;
    for(int j = 0; j< n-i-1; j++){
      if(arr[j+1]<arr[j]){
        swap(arr[j+1], arr[j]);
        isswap = true;
      }
      
    }
    if(isswap = false){
      break;
    }
  }
}
int main(){
  int n ;
  cin>> n;
  int arr[n];
  for(int i = 0; i<n; i++){
    cin>> arr[i];
  }
  bubblesort(arr,n);
  for(int i = 0; i<n; i++){
    cout<< arr[i]<<" ";
  }
  return 0;
}
