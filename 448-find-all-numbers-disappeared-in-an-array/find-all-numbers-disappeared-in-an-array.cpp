class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    map<int, bool> seen;

    // Mark all numbers present in the array
    for (int i = 0; i < n; i++) {
        seen[nums[i]] = true;
    }

    vector<int> result;

    // Check from 1 to n which number is missing
    for (int i = 1; i <= n; i++) {
        if (seen.find(i) == seen.end()) {
            result.push_back(i);
        }
    }

    return result;
}

};