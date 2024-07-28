#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, s, e, mid){

};
void mergesort(vector<int> &arr, int n){

}
int main(){
  int n ;
  cin>> n;
  vector<int> arr(n);
  for(int i = 0; i<n; i++){
    cin>> arr[i];
  }
  mergesort(arr,n);
  for(int i = 0; i<n; i++){
    cout<< arr[i]<<" ";
  }
  return 0;
}