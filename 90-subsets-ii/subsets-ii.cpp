class Solution {
public:
    void solve(vector<int>& nums, int idx, vector<int> &temp, vector<vector<int>> &result){
        if(idx == nums.size()){
            result.push_back(temp);
            return;
        }
        
        // Exclude current number and skip all its duplicates for the "exclude" branch
        int next = idx + 1;
        while(next < nums.size() && nums[next] == nums[idx]) next++;
        solve(nums, next, temp, result);

        // Include current number
        temp.push_back(nums[idx]);
        solve(nums, idx + 1, temp, result);
     temp.pop_back(); // backtrack karna isliye jaruri hai kyuki ek baar hmne 2 choices m se ek choice p decision leke base case par pahuch gye idx == nums.size() ho gya phir baad m backtrack karke temp m se elements pop karo taki jo choices phle nhi li thi unko leke explore kar sake baaki k possibilities 
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(), nums.end()); // sort first to group duplicates
        solve(nums, 0, temp, result);
        return result;
    }
};