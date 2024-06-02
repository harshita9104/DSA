// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 // Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]

vector<int> twoSum(vector<int>& nums, int target) {
        //brute force app
        //here we pick an element of arr and then check wether its um with any other element equlas to target or not
        //the second loop decides the other element , it starts from i+1 since the check for the element and element occuring previous to i has been earlier
        //and you may not use the same element twice.
        for(int i = 0; i< nums.size(); i++){
            for(int j = i+1; j< nums.size(); j++){
                if(nums[i]+ nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};

//better 
//if i want to solve it in O(n) that means iterating on an element once, and i am looking for one more element to add to it to give the target.
//to figure out the rem sum elemnt exist in arr or not
//easiest way is hashing, if you have stored the element somewhere u could easily retract from it.
//use map data structure that will tell the index as well and u could find out if it is present in hashmap or not ,by finding that the element is pointing to end or not.
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        int rem = 0;
        for(int i = 0; i< nums.size(); i++){
            rem = target - nums[i];
            //if rem element is existing in hashmap then it wont point to last iterator
            if(mpp.find(rem) != mpp.end()){
                return {i, mpp[rem]};
            }
            mpp[nums[i]] = i;
        }
        //if no element found return empty vector
        return {};
    }
};
//TC - O(nlogn) in case of ordered map 
//and in umorderend map BC, AC - O(n) but worst case can be O(n^2
//SC - O(n)

// to avoid this extra space 
//we can use 2 pointer app

//optimal
//the given code wont work for returning the indexes as the original indexes of elements gets changed when we sort them 
//this code will work for the second variety where we just want to know if the sum exists in arr or not.
//2 pointer app


bool twoSum(vector<int>& nums, int target) {
        
        //keep a left and right pointer at both ends and add those elements to check if it is equal to target
        //sort the array first
        //if the sum is less than target we neet to increment it so move left pointer ahead
        //if sum is more then we need to reduce it so move right pointer behind
        //and the moment left and right croses no such elemnt exist
        int left = 0;
        int right = nums.size() -1;
        int sum = 0;
        sort(nums.begin(), nums.end());
        while(left< right){
            sum = nums[left] + nums[right] ;
            if(sum< target){
                left++;
            }else if(sum > target){
                right--;
            }else if (sum == target) {
                return yes ;
            }

        }
        return no;
    }

