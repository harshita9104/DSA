// The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stocks price for all n days. 
// The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the given day is less than or equal to its price on the current day.
// For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

// Example 1:

// Input: 
// N = 7, price[] = [100 80 60 70 60 75 85]
// Output:
// 1 1 1 2 1 4 6
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> stockspan(int arr[], int n){
  vector<int> v;
  stack<pair<int, int>> s;
  //observations
  //standing at an index if we look in left to count the elem who are smaller or eq to current index elem
  //then we stop our serach at next greater to left elem
  //second observation is the count of smaller or eq to elem in left is equal to current index - index of its NGL elem
  // so we store in stack NGL along with the  the index of elem
  //and for each index we store the index of its corresponding NGL elem in vector v
  // so that we can obtain stock span for each index by doing i - v[i]
  for(int i = 0; i<n ; i++){
    if(s.size() == 0){
      v.push_back(-1);
    }else if(s.size() >0 && s.top().first > arr[i] ){
            v.push_back(s.top().second);
        }else if(s.size() >0 && s.top().first <= arr[i]){
            while(s.size() >0 && s.top().first <= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(-1);

            }else{
                v.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});

  }
  for(int i = 0; i<n ; i++){
    cout<< i - v[i]<<" ";
  }
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i = 0; i<n; i++){
    cin>> arr[i];
  }
  stockspan(arr,n);
  return 0;
}