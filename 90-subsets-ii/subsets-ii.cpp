class Solution {
public:

    // Recursive function to generate all subsets and store them in a set for uniqueness
    void solve(vector<int>& ip, vector<int>& op, set<vector<int>> &st){
        if(ip.size() == 0){
            st.insert(op); // insert current subset (set will handle duplicates)
            return;
        }
        vector<int> op1 = op;           // Exclude current element
        vector<int> op2 = op;
        op2.push_back(ip[0]);           // Include current element
        vector<int> newIp(ip.begin() + 1, ip.end());
        solve(newIp, op1, st);          // Recurse without current element
        solve(newIp, op2, st);          // Recurse with current element
    }
    
        
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//If you don’t sort:
// Your recursion can generate both [1,2] and [2,1] as separate subsets.
// These are different vectors, so the set will treat them as distinct subsets, even though mathematically they are the same subset.
//set<vector<int>> only removes exact duplicates, not permutations.
// Sorting ensures that subsets with the same elements are inserted in the same order, so only true duplicates are removed.

        sort(nums.begin(), nums.end()); // Sort to ensure duplicates handled correctly
        set<vector<int>> st;
        vector<int> op;
        solve(nums, op, st);
        vector<vector<int>> ans;
        // Copy from set to answer vector
        for(const auto& subset : st){
            ans.push_back(subset);
        }
        return ans;
    }
};