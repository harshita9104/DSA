class Solution {
public:
    void solve(vector<int>& ip, vector<int>& op, vector<vector<int>>& ans){
        if(ip.size() == 0){
            ans.push_back(op);
            return;
        }
        vector<int> op1 = op;
        vector<int> op2 = op;
        op2.push_back(ip[0]);
        vector<int> newIp(ip.begin() + 1, ip.end());
        solve(newIp, op1, ans);
        solve(newIp, op2, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(nums, op, ans);
        return ans;
    }
};