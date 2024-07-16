// Professor X wants his students to help each other in the chemistry lab. He suggests that every student should help out a classmate who scored less marks than him in chemistry and whose roll number appears after him. But the students are lazy and they don't want to search too far. They each pick the first roll number after them that fits the criteria. Find the marks of the classmate that each student picks.
// Note: one student may be selected by multiple classmates.

// Example 1:

// Input: N = 5, arr[] = {3, 8, 5, 2, 25}
// Output: 2 5 2 -1 -1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;    
    vector<int> smallertoright(vector<int> arr, int n) 
    { 
      vector<int> v;
      stack<int> s;
        // Your code goes here
                //since standing at ith elem we have to check i-1th elem is smaller or not
        //so the loop need to traverse from left to right and put elem in stack in that order
        for(int i = n-1; i>=0 ; i--){
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
                   //we got smaller elem on stack top now push it in vector
                   v.push_back(s.top());
               }
           }
           //before moving to next index in iteration push this elem in stack whose next greater we have obtained
           s.push(arr[i]);
        }
        reverse(v.begin(),v.end());
        for(int i = 0; i<n; i++){
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
  smallertoright(arr, n);
  return 0;

}