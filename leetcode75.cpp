//Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.
// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
void sortColors(vector<int>& nums) {
        //initialise index as 0 it is the index with which u will swap if u found a 0  in whole arr initially and then index++ and then if u found 1.
        //run a loop from 0 to 2 and an inner loop across nums
        // check if nums[j] == i (i,e. 0/1/2) and swap nums[index] with
        // nums[j] and then index++ if u have swapped.
        int index = 0;
        for(int i =0; i<3; i++){
            for(int j = 0; j< nums.size(); j++){
                if(nums[j] == i){
                    swap(nums[index], nums[j]);
                    index++;
                }
            }
        }
}
//better
 void sortColors(vector<int>& nums) {
        int cnt0 =0; int cnt1 = 0; int  cnt2 = 0;
        for(int i = 0; i< nums.size(); i++){
            
            if(nums[i] == 0){
                cnt0++;
            }
            if(nums[i] == 1){
                cnt1++;
            }
            if(nums[i] == 2){
                cnt2++;
            }
            
            
        }
        for(int j = 0; j<cnt0; j++){
            nums[j] = 0;
        }
         for(int k = cnt0; k<cnt0 + cnt1; k++){
            nums[k] = 1;
        }
         for(int l = cnt0 + cnt1; l<nums.size(); l++){
            nums[l] = 2;
        }
    }

    //optimal solution
    //dutch national flag algorithm
    //[0, low-1]  -> 0
    //[low, mid-1] -> 1
    //[mid, high]  -> unsorted 0/1/2
    //[high +1 , n-1] -> 2
    
