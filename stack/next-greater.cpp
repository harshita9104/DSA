// Given an array arr[ ] of n elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
// If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

// Examples

// Input: arr[] = [1 3 2 4], n = 4
// Output: 3 4 4 -1
// Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void nextLargerElement(vector<int> arr, int n){
vector<int> v;
       stack<int> s;
       //since standing at ith index i have to check that i+1 th element is greater or not
       //so i+1 th elem shd be present in top of stack 
       //so we need to traverse reverse in arr to push elements in stack after finding its next greater elem 
       for(int i = n-1; i >= 0; i--){
           if(s.size() == 0){
               v.push_back(-1);
           }
           //we will push an elem in vector if its is greater than arr elem 
           //order of stack ensures the elm at top of stack is nearest to right of current index
           //check if stack is not empty before accessing its top elem
           else if(s.size() >0 && s.top() > arr[i]){
               v.push_back(s.top());
           }else if(s.size() >0 && s.top() <= arr[i]){
               //we will keep poping elem out of stack untill we find greater elem on stack top or stack becomes empty
               //for that we need to run a loop
               while(s.size() >0 && s.top() <= arr[i]){
                   s.pop();
               }
               //we will come out of this while loop if one of the conditions becomes false
               if(s.size() == 0){
                   v.push_back(-1);
               }else{
                   //we got greater elem on stack top now push it in vector
                   v.push_back(s.top());
               }
           }
           //before moving to next index in iteration push this elem in stack whose next greater we have obtained
           s.push(arr[i]);
       }
       //since we have found the next greater of last elm first now reverse the vector to obtain output
       reverse(v.begin(),v.end());
      for(int i = 0; i<n;i++){
        cout<<v[i]<<" ";
      }

}
int main(){
  int n;
  cin>>n;
  //mistake arr[] nhi arr(n)
  vector<int> arr(n);
  for(int i = 0; i<n ; i++){
    cin>>arr[i];
  }
  nextLargerElement(arr,n);
  return 0;

}