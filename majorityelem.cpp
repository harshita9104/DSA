// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
int majorityElement(vector<int>& nums) {
        //the element which occur more than n/2 times would be located at mid after we sort it.
        sort(nums.begin(), nums.end());
        int mid = nums.size()/2;
        return nums[mid];
    }

    //brute force app- take too much time
  int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
          //mistake- the count need to be reset after each iteration
            int count = 0;
            for(int j = 0; j <n; j++){
                if(nums[i] == nums[j]){
                    count++;
                    if(count > n/2){
                        return nums[i];
                        break;
                    }
                }

            }
        }
        return -1;

    }
//better - use hashing
//TC - ordered map then - O(n logn ) , unordered map - O(n)
int majorityElement(vector<int>& nums) {
        map<int, int> mpp;
        for(int i = 0; i< nums.size(); i++){
            mpp[nums[i]]++;


        }
        //now iterate in map to check if the second element ie, the frequency of any elem is > n/2 or not.
        for(auto it: mpp){
            //iterator will be pointing at one map elem and to access its first and second value 
            if(it.second > nums.size()/2){
                return it.first;
            }
        }
        return -1;
    }
//optimal
//moore's voting algo apply
//here we first assume an element to be majority ele & then based on the concept 
//that  if while iterating thr arr we get the majority ele then lets inc the count, and if we get some other ele then cnt-- , this way we can see if other ele cancel out this ele or not if in case the cnt = 0 that is the ele canceled out the majority ele that means upto tht point it is not majority elem , so lets assume a new majority ele and see if it cancel out or not by others
//after getting some majority ele we also need to check if it occurs more than n/2 times or not.
int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority = nums[0];
        int n=0;
        for(int i = 0; i< nums.size(); i++){
            if(count == 0){
                majority = nums[i];
            }
            
            if(nums[i] == majority){
                count++;

            }else{
                count--;
            }
            
        }
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == majority){
                n++;
                

            }
            if(n > nums.size()/2){
                return majority;
            }
        }
        return -1;
    }
