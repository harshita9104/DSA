class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //no of distict number arr contains is decided by the size of the arr
        int n = nums.size();
        vector<int>v(n+1,-1);//ek arr lo the size of arr should be the range of nums jiske index agar nums m aa rha to us index k correspoding val 1 kardo agar nahi aa rha hoga to value -1 hi rhegi 
        for(int i = 0; i<n; i++){
        v[nums[i]] = 1;
        }
        for(int i = 0; i< v.size(); i++){
            if(v[i] == -1){
                return i;
            }
        }
        return -1;

    }
};