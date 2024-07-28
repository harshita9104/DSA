#include<iostream>
using namespace std;
//imagine the arr has two parts sorted and unsorted , so we need to find the min elem from unsorted portion and push it in sorted protion and this way the sorted portion keep expanding and unsorted keep shrinking
//minindex is the index jisko swap karna hai with minelem of unsorted arr
//this minindex will be initialised with i 
void selectionsort(int arr[], int n){
  for(int i = 0; i<n-1; i++){
    int minindex = i;
    //loop to find min in unsorted portion and then swap it with current i
    //if arr is already sortd then the value of min index will not change and arr[i] khudse hi swap ho jaega
    for(int j = i+1; j<n;j++){
      if(arr[j]< arr[minindex]){
        minindex = j;
      }
    }
    swap(arr[i], arr[minindex]);
  }

}
int main(){
  int n ;
  cin>> n;
  int arr[n];
  for(int i = 0; i<n; i++){
    cin>> arr[i];
  }
  selectionsort(arr,n);
  for(int i = 0; i<n; i++){
    cout<< arr[i]<<" ";
  }
  return 0;
}