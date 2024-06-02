//Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

//optimal solution
    //dutch national flag algorithm
    //hypothetical arr
    //[0, low-1]  -> 0
    //[low, mid-1] -> 1
    //[mid, high]  -> unsorted 0/1/2
    //[high +1 , n-1] -> 2
    

//initially take mid = 0, high = n-1, and low = 0 , as it is starting point.
//our algo will work in terms of a[mid]
// if a[mid] == 0, swap it with 1 which should be arr[low] (look at the code if the a[mid] would have been 1 instead of 0 then mid++ , so the a[low] would be 1 now)
//this way we brought 0 in starting so we should move low++ and since before mid (from where unsorted arr starts there shd be 1s so we will move mid++)

//if a[mid] == 1  then simply move mid++ so that acc to our order mid-1 could be 1.

// if a[mid] == 2 then swap it with a[high] as the 2s need to be in the end of arr and  high -- as we decided to keep unsorted elem from mid to high.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};