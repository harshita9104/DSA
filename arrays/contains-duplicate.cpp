// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: true
// Example 2:

// Input: nums = [1,2,3,4]
// Output: false

bool containsDuplicate(vector<int>& nums) {
        //use of hash maps
        map<int,int> mpp;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            //we consider the key of hashmap as elem of arr, and the value is the freq of elem of arr.
            mpp[nums[i]]++;

        }
        //after the hashmap is ready iterate thr the map and check the second parameter of hashmap i.e, the freq of the elm
        for(auto it: mpp){
            if(it.second >=2){
                return true;
            }
        }
        return false;
    }
