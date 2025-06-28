class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //counting sort
        // map m store krlo , phir min or max elem find karlo
        //phir minelem or max elem tak loop run krke jitni baar map m value hai nums[i]
        //m ddaldo
        unordered_map<int, int> mp;
        for(int &num : nums){//jaise iterate kr rhe nums[i] is num 
            mp[num]++;
        }
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());
        int i =0;//to keep track of nums 
        for(int num = min; num<= max; num++){
        while(mp[num] >0){
            nums[i] = num;
            i++;
            mp[num]--;//ek elem nums arr m daal diya to count km kro
            }
        }
        return nums;
    }
};