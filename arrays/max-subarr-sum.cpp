//kadane's algorithm
#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
maxsubarrsum(int arr[], int n){
  int maxsum = INT_MIN;
  int currsum = 0;
  //we iterate through the loop the moment the currsum becomes neg no need to carry it forward as it would only contribute to decrement in currsum
  //find the maxsum for each iteration 
  for(int i =0; i<n; i++){
    currsum += arr[i];
    //find maxsum earlier only suppose if the arr contains only neg elem then the maxsum will be also neg value 
    //so currsum shd not be reduce to 0 , find the max sum before only
    maxsum = max(maxsum, currsum);
    //if currsum becomes neg we need to reset it to 0
    if(currsum<0){
      currsum = 0;
    }
  }
  return maxsum;
}
int main(){
  int arr[] = {3,-1,4,-9,8,9,-1,-4};
  int n = sizeof(arr)/sizeof(int);
  cout<<maxsubarrsum(arr,n);
  return 0;

}