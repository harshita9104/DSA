//Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity
int searchInsert(vector<int>& nums, int target) {
        int n =  nums.size();
        int low = 0; int high = n-1;
        int mid = low+(high - low)/2;
        int ans = n;//if the element is greater than all the elements in arr
        while(low<= high){
            //suppose the target is not present in arr
            //u can insert target at a place where the elem is greater than the target so that when the target is inserted at that place the current elem shifts and the sorted order is not disturbed.
            if(nums[mid] >= target){
                ans = mid;
                high =  mid-1;
            }else{
                low =  mid+1;
            }
            //mistake
            //update the value of mid after each iteration
            mid = low+(high- low)/2;
        } 
        return ans;
    }