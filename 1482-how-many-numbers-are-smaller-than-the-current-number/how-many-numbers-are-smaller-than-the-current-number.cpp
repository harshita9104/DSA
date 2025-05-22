class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        //this problem is very easy if the arr becomes sorted then the index o the elem will be the ans tht how many no are smaller than tht elem but we cant change the arr so we sort a diff arr which is same as nums

        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        //now store the index of elem in sorted vec arrcores in map 
        map<int, int> mp;
        for(int i =0; i<vec.size(); i++){
            //since numbers repeat bhi honge to net iteration m uska index change ho jaega or galat answer aa jaega kyuki numbers smaller than duplicate elem is eq to only the index of only 1st occ so dont let duplicate numbers change the val in map
            if(mp.find(vec[i]) == mp.end()){//if the elem is not present in map then only insert it in map
                mp[vec[i]] = i;
            }
           
        }
        //since map stores the no. of elem smaller than that elem coresponding to that elem so we will access that number using map  and put the value we get in the palce of nums[i] in nums arr this way we modified the nums without using extra arr 
        for(int i =0; i<nums.size(); i++){
            nums[i] = mp[nums[i]];
        }
        return nums;


    }
};