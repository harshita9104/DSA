class Solution {
public:
    // Main function to generate all possible subsets (the power set)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;     // This will store all the subsets
        vector<int> curr;            // Temporary vector to build each subset
        helper(nums, 0, curr, ans);  // Start recursion from index 0
        return ans;
    }
    
    // Recursive helper function to generate subsets
    void helper(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& ans) {
        // Base case: if we've considered all elements
        if(idx == nums.size()) {
            ans.push_back(curr); // Add current subset to the answer
            return;
        }
        // Exclude the current element and move forward
        helper(nums, idx + 1, curr, ans);
        
        // Include the current element and move forward
        curr.push_back(nums[idx]);
        helper(nums, idx + 1, curr, ans);
        
        // Backtrack: remove the current element before returning
        curr.pop_back();
    }
};