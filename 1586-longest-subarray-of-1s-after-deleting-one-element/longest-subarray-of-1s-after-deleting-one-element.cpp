class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(); // The size of the input array
// The code aims to find the length of the longest subarray consisting of only 1's after deleting at most one element (0 or 1) from the original array.
// The variable left represents the left pointer of the sliding window, which defines the subarray.
// The variable zeros keeps track of the number of zeroes encountered in the current subarray.
// The variable ans stores the maximum length of the subarray found so far.
// The code iterates over the array using the right pointer right.
// If nums[right] is 0, it means we encountered a zero in the array. We increment zeros by 1.
// The while loop is used to adjust the window by moving the left pointer left to the right until we have at most one zero in the subarray.
// If nums[left] is 0, it means we are excluding a zero from the subarray, so we decrement zeros by 1.
// We update the left pointer by moving it to the right.
// After adjusting the window, we calculate the length of the current subarray by subtracting the number of zeroes from the total length right - left + 1. We update ans if necessary.
// Finally, we check if the entire array is the longest subarray. If it is, we subtract 1 from the maximum length to account for the one element we are allowed to delete. We return the resulting length.
        int left = 0; // The left pointer of the sliding window
        int zeros = 0; // Number of zeroes encountered
        int ans = 0; // Maximum length of the subarray

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                zeros++; // Increment the count of zeroes
            }

            // Adjust the window to maintain at most one zero in the subarray
            while (zeros > 1) {
                if (nums[left] == 0) {
                    zeros--; // Decrement the count of zeroes
                }
                left++; // Move the left pointer to the right
            }

            // Calculate the length of the current subarray and update the maximum length
            ans = max(ans, right - left + 1 - zeros);
        }

        // If the entire array is the subarray, return the size minus one; otherwise, return the maximum length
        return (ans == n) ? ans - 1 : ans;
    }
};