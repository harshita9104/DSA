class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //in order to do this question in O(1) TC u can use hashmap which stores elem, index in map
        map<int,int> mp;
        //standing at one elem we will look for the rem = target- curr elem in map if we are able to find it we will return the index of those elem if not we will insert curr elem and its coresponding index in map and move to the next elem
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int elem = target - nums[i];
            if(mp.find(elem) != mp.end()){//agar map m elem find krne par map k end m point nhi kr rha h it means vo elem map m exist krta hai 
            return{i,mp[elem]};

            }
            mp[nums[i]] =i;//insert value(index) coresponding to key (elem)
        }
        return {};
    }
};