#include<iostream> 
#include<bits/stdc++.h>

using namespace std;
void reverse(int arr[], int n ){
  // for(int i = 0; i<=n/2; i++){
  //   swap(arr[i], arr[n-i-1]);

  // }
  //2 pointer app
  int start = 0;
  int end = n-1;
  while(start<= end){
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}
int main(){
  int arr[] = {2,3, 4, 6, 8, 9,0};
  int n = sizeof(arr)/sizeof(int);
  reverse(arr, n);
  for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  return 0;

}
