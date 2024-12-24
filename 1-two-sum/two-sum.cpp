class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //hashmap ka use krenge kyuki usme elem find or retreve krne ki time comp O(1) hoti hai extra loop nhi chlana pdega to find the remaining value from the target
        //ek hi loop chlana hai , ek elem p khade hoke dekhna hai ki remaining value map m h kya agar hai to vahi p return kardo nhi to is elem or uske corresponding index ko map m store karke aage badho
        int n = nums.size();
        map<int, int> mp;//stores elem, index
        for(int i = 0; i<n; i++){
            int rem = target - nums[i];
            if(mp.find(rem) != mp.end()){
                return{mp[rem],i};
            }
            mp[nums[i]] = i;

        }
        //agar target k eq do elem nhi mile loop k end m to empty arr return kardo
        return{};

    }
};