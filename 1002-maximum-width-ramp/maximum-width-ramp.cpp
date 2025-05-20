
        // Step 1: Build a stack with indices of a decreasing sequence
// It ensures any later element >= top of stack will form a valid ramp
// For example: nums = [6, 0, 8, 2, 1, 5]
// Stack holds: indices of 6, 0 (positions 0, 1) because they are potential i’s

// Step 2: Iterate from the end of array and for each j,
// try to find the earliest i such that nums[i] <= nums[j]
// We can safely pop i’s as we move backward,
// because the ramp (j - i) gets wider for earlier i

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        // Step 1: Build a decreasing monotonic stack of indices
        for (int i = 0; i < n; ++i) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }

        int ans = 0;

        // Step 2: Traverse from right to left to find the max ramp
        for (int j = n - 1; j >= 0; --j) {
            // While we have a valid ramp condition
            while (!st.empty() && nums[j] >= nums[st.top()]) {
                ans = max(ans, j - st.top());
                st.pop();
            }
        }

        return ans;
    }
};


//         // int i = 0;
//         // int j = nums.size() - 1;
//         // int count2 = j;
//         // int count1 = i;
//         // int ans = 0;

//         // while (i < j) {
//         //     if (nums[i] <= nums[j]) {
//         //         ans = max(ans, j - i);
//         //         i++; // \U0001f7e2 Move i forward to explore more ramps
//         //     } else {
//         //         // \U0001f534 These loops must be bounded to avoid infinite loops
//         //         while (count1 < j && nums[count1] > nums[j]) {
//         //             count1++;
//         //         }
//         //         while (i < count2 && nums[i] > nums[count2]) {
//         //             count2--;
//         //         }

//         //         // \U0001f7e2 Now update ans with max ramp using narrowed count1 and count2
//         //         ans = max({ans, j - count1, count2 - i});
//         //          // do j-- Shrink the right  end (important to break the outer loop)
//         //         break;
//         //     }
//         // }

//         // return ans;
        


//     }
// };
//brute force
// class Solution {
// public:
//     int maxWidthRamp(vector<int>& nums) {
//         int n = nums.size();
//         int ans = 0;

//         // Try every possible i
//         for (int i = 0; i < n; ++i) {
//             // For current i, find the farthest j such that nums[i] <= nums[j]
//             for (int j = n - 1; j > i; --j) {
//                 if (nums[i] <= nums[j]) {
//                     ans = max(ans, j - i);
//                     break; // no need to check smaller j for this i
//                 }
//             }
//         }

//         return ans;
 