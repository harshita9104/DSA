#include <iostream>
#include <bits/stdc++.h>
using namespace std;
printsubarr(int arr[], int n){
  //i is start of subarr 
  for(int i = 0; i<n; i++){
    //start from a given index and end at every index present from start to n-1
    //j is end of subarr 
    for(int j = 0; j<n; j++){
      for(int k = i; k<=j; k++){
        cout<<arr[k];
      }
      //comma after each subarr
    cout<<", ";
      
    }
    // change the line when start index changes
    cout<<endl;
    
  }
  
  
}
int main(){
  int arr[] ={ 2,4,5,7,8,9};
  int n = sizeof(arr)/sizeof(int);
  printsubarr(arr,n);
  return 0;
}
