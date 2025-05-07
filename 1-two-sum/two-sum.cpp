class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //ek elem par khade hokar remaining value ko find karne m extra tc lgegi usko avoid karne k liye
        //use hashmap jisme elem ko find krne or retrieve krne ki time complexity O(1) hoti h map wil, store elem as key and its coresponding index as value
        //ek hi loop chlao or remaining value = (target - current elem) ko map m find kro agar mil jata hai to vahi p uska index return kardo nhi to 
        //us elem or uske index ko map m daalke , loop m aage badho
        int n = nums.size();
        map<int, int> mp;//elem, index
        for(int i = 0; i<n ; i++){
            int elem = target - nums[i];
            if(mp.find(elem) != mp.end()){//this means elem ko find kro if doesnt point at the end of map upon looking for it , means it is present inside map so return it
            return {i,mp[elem] };

            }else{
                mp[nums[i]] = i;
            }
        }
    return {}; 
    }
};