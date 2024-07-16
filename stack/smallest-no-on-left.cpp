//Given an array a of integers of length n, find the nearest smaller number for every element such that the smaller element is on left side.If no small element present on the left print -1.

// Example 1:

// Input: n = 3
// a = {1, 6, 2}
// Output: -1 1 1
// Explaination: There is no number at the 
// left of 1. Smaller number than 6 and 2 is 1.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void leftSmaller(int n, int arr[]){
        // code here
        vector<int> v;
        stack<int> s;
        //since standing at ith elem we have to check i-1th elem is smaller or not
        //so the loop need to traverse from left to right and put elem in stack in that order
        for(int i = 0; i<n ; i++){
            if(s.size() == 0){
               v.push_back(-1);
           }
           //we will push an elem in vector if its is smaller than arr elem 
           //order of stack ensures the elm at top of stack is nearest to right of current index
           //check if stack is not empty before accessing its top elem
           else if(s.size() >0 && s.top() < arr[i]){
               v.push_back(s.top());
           }else if(s.size() >0 && s.top() >= arr[i]){
               //we will keep poping elem out of stack untill we find smaller elem on stack top or stack becomes empty
               //for that we need to run a loop
               while(s.size() >0 && s.top() >= arr[i]){
                   s.pop();
               }
               //we will come out of this while loop if one of the conditions becomes false
               if(s.size() == 0){
                   v.push_back(-1);
               }else{
                   //we got smaller elem on stack top now push it i3n vector
                   v.push_back(s.top());
               }
           }
           //before moving to next index in iteration push this elem in stack whose next greater we have obtained
           s.push(arr[i]);
        }
        for(int i = 0; i<n; i++){
          cout<<v[i]<<" ";
        }
    }
    int main(){
  int n;
  cin>>n;
  //mistake arr[] nhi arr(n)
  int arr[n];
  for(int i = 0; i<n ; i++){
    cin>>arr[i];
  }
  leftSmaller(n, arr);
  return 0;

}