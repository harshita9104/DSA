//You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should return the array of nums such that the the array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.

//brute
vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        
        for(int i = 0; i< nums.size(); i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);

            }else if(nums[i]<0){
                neg.push_back(nums[i]);

            }

        }
        int index = 0;
        for(auto it: pos){
            
            nums[index] = it;
            index= index +2;
        }
        int ind = 1;
        for(auto it: neg){
            
            nums[ind] = it;
            ind= ind +2;
        }
        return nums;

    }
