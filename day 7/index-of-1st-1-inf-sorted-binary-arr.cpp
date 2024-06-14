// C++ implementation to find the index of first 1
// in an infinite sorted array of 0's and 1's
#include <bits/stdc++.h>
using namespace std;
 
// function to find the index of first '1'
// binary search technique is applied
int indexOfFirstOne(int arr[], int low, int high)
{
  int mid = low+(high - low)/2;
  int ans = 0;
  while(low<= high){
    mid = low+(high - low)/2;
    if(arr[mid] == 1){
      ans  =  mid;
      high = mid-1;
      
    }else if(arr[mid]< 1){
      low = mid+1;
    }
  }
  return ans;
}
// function to find the index of first 1 in
// an infinite sorted array of 0's and 1's
int posOfFirstOne(int arr[])
{
    // find the upper and lower bounds between
    // which the first '1' would be present
    int l = 0, h = 1;
 
    // as the array is being considered infinite
    // therefore 'h' index will always exist in
    // the array
    while (arr[h] == 0) {
 
        // lower bound
        l = h;
 
        // upper bound
        h = 2 * h;
    }
 
    // required index of first '1'
    return indexOfFirstOne(arr, l, h);
}
 
// Driver program to test above
int main()
{
    int arr[] = { 0, 0, 1, 1, 1, 1 };
    cout << "Index = "
         << posOfFirstOne(arr);
    return 0;
}
