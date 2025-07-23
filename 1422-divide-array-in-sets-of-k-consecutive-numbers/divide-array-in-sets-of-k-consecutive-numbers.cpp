class Solution {
public:
   bool isPossibleDivide(vector<int>& nums, int k) {
    // If the total number of elements is not a multiple of k,
    // it's impossible to divide them into groups of k consecutive numbers.
    if(nums.size() % k != 0) return false;

    // Sort the numbers so we can find consecutive sequences easily.
    sort(nums.begin(), nums.end());

    // Create a boolean array to keep track of which numbers have been used in groups.
    vector<bool> used(nums.size(), false);

    // Iterate through each number in the sorted array.
    for(int i = 0; i < nums.size(); ++i) {
        // If this number has already been used in a group, skip it.
        if(used[i]) continue;

        // Start forming a group with the current number.
        int count = 1; // Number of elements in the current group.
        used[i] = true; // Mark this number as used.
        int prev = nums[i]; // Store the previous number in the group.

        // Try to find the next k-1 consecutive unused numbers to form a group.
        for(int j = i + 1; j < nums.size() && count < k; ++j) {
            // If nums[j] is not used and is exactly 1 greater than the previous number,
            // it can be included in the current group.
            if(!used[j] && nums[j] == prev + 1) {
                used[j] = true; // Mark this number as used.
                prev = nums[j]; // Update the previous number.
                ++count; // Increment the group count.
            }
        }

        // If we couldn't find k consecutive numbers for this group, return false.
        if(count < k) return false;
    }

    // All numbers have been grouped into sets of k consecutive numbers.
    return true;

    }
};