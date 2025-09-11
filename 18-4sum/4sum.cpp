class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) return res;  // Not enough numbers
        
        sort(nums.begin(), nums.end()); // Step 1: Sort
        
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate for i
            
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicate for j
                
                int low = j + 1, high = nums.size() - 1;
                
                while (low < high) {
                    long total = (long)nums[i] + (long)nums[j] + (long)nums[low] + (long)nums[high];
                    
                    if (total == (long)target) {
                        res.push_back({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;
                        // Skip duplicates for low and high
                        while (low < high && nums[low] == nums[low - 1]) low++;
                        while (low < high && nums[high] == nums[high + 1]) high--;
                    }
                    else if (total < target) {
                        low++; // Need a bigger sum
                    }
                    else {
                        high--; // Need a smaller sum
                    }
                }
            }
        }
        return res;
        
    }
};