//leetcode premium
#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int low,int high, int x){
  
  while(low<= high){
    int mid = low+(high - low)/2;
     if(arr[mid] == x) {
            return mid;
        }

        //go to right wala part
        if(x > arr[mid]) {
            low = mid + 1;
        }
        else{ //key < arr[mid]
            high = mid - 1;
        }

        
  }
  return -1;

}
int findPos(int arr[], int x){
  int low = 0; int high = 1;
  //this loop works untill the key < arr[high] and it is under our search space so that we can apply binary search on it
  while(arr[high ]<= x){
    // store previous high
         // double high index
    low = high ; 
    high = high *2;
  }
  // at this point we have updated low and
    // high indices, Thus use binary search 
    // between them
  return binarySearch(arr,low,high,x);

  }
  
  

int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 
                               140, 160, 170};
    int ans = findPos(arr, 10);
    if (ans==-1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans;
    return 0;
}