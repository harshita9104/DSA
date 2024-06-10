//Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.


class Solution {
public:
    int findMin(vector<int>& nums) {
        //since point of rotation will lie in unsorted half as it is the point the order gets distorted
        //and point of rotation will surely have min elem
        //so we will eliminate sorted portion but sorted half can also have min elem in few cases, spo we will store its min and then eliminate it.
        int n = nums.size();
        int low = 0; int high = n-1;
        int mid = low+(high - low)/2;
         int ans = INT_MAX;
        while(low<=high){
           
            mid = low+(high - low)/2;
            if(nums[low]<= nums[mid]){
                //left sorted
                //mistake - take the min of the ans 
                ans = min(ans,nums[low]);
                low = mid+1;
            }else{
                //right sorted 
                //mistake store the elem not the index
                ans = min(ans,nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};