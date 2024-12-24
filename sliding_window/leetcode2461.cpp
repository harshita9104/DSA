// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

// The length of the subarray is k, and
// All the elements of the subarray are distinct.
// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

// A subarray is a contiguous non-empty sequence of elements within an array.
// Example 1:

// Input: nums = [1,5,4,2,9,9,9], k = 3
// Output: 15
// Explanation: The subarrays of nums with length 3 are:
// - [1,5,4] which meets the requirements and has a sum of 10.
// - [5,4,2] which meets the requirements and has a sum of 11.
// - [4,2,9] which meets the requirements and has a sum of 15.
// - [2,9,9] which does not meet the requirements because the element 9 is repeated.
// - [9,9,9] which does not meet the requirements because the element 9 is repeated.
// We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions



int maxSubarraySumDistinct(vector<int>& nums, int k) {
    int n = nums.size();
    int maxSum = 0; // Initialize the maximum sum to 0

    // Iterate through all possible subarrays of length k
    for (int i = 0; i <= n - k; ++i) {
        unordered_set<int> elements; // Set to track distinct elements
        int currentSum = 0; // Initialize current subarray sum to 0
        bool allDistinct = true; // Flag to check if all elements are distinct

        // Check if all elements in the subarray are distinct
        for (int j = i; j < i + k; ++j) {
            if (elements.find(nums[j]) != elements.end()) {
                // If element is already in the set, subarray is not distinct
                allDistinct = false;
                break;
            }
            // If element is not in the set, add it and update current sum
            elements.insert(nums[j]);
            currentSum += nums[j];
        }

        // If all elements in the subarray are distinct, update the maximum sum
        if (allDistinct) {
            maxSum = max(maxSum, currentSum);
        }
    }

    return maxSum; // Return the maximum sum of all subarrays with distinct elements
}
//optimal
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) return 0; // If the array size is less than k, return 0

    unordered_set<int> elements; // Set to track distinct elements
    long long  maxSum = 0, currentSum = 0;
    int start = 0; // Initialize maxSum, currentSum, and start index

    // Iterate through the array using end as the right boundary of the window
    for (int end = 0; end < n; ++end) {
        // Slide the window to the right until all elements are distinct
        while (elements.find(nums[end]) != elements.end()) {
            elements.erase(nums[start]); // Remove the element at start
            currentSum -= nums[start]; // Subtract the element at start from current sum
            start++; // Move the start index to the right
        }

        // Add the new element
        elements.insert(nums[end]); // Insert the new element into the set
        currentSum += nums[end]; // Add the new element to current sum

        // If the window size is k, update the maximum sum
        if (end - start + 1 == k) {
            maxSum = max(maxSum, currentSum); // Update maxSum if currentSum is higher
            // Slide the window to the right by removing the start element
            elements.erase(nums[start]); // Remove the element at start
            currentSum -= nums[start]; // Subtract the element at start from current sum
            start++; // Move the start index to the right
        }
    }

    return maxSum; // Return the maximum sum of all subarrays with distinct elements
}
};