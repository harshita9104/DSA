class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // After you've found that sum >= target, you should try to shrink the window from the left (i) as much as possible while keeping the sum >= target.


        int i = 0;
        int j = 0;
        int sum = 0;
        int subarr = INT_MAX;

        while (j < nums.size()) {
            sum += nums[j];

            // Try to shrink the window from the left as long as sum >= target
            while (sum >= target) {
                subarr = min(subarr, j - i + 1);  // update min length
                sum -= nums[i];  // remove from left
                i++;
            }

            j++;
        }

        return (subarr == INT_MAX) ? 0 : subarr;

    }
};