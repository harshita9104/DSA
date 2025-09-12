class Solution {
public:
    string orderlyQueue(string s, int k) {
        //Rotating the string for k = 1 can be optimized by directly considering minimal rotations.
// For k > 1, sorting is already efficient.
// Optimized Thought Process
// Case 1: k = 1:
// Generate all rotations using string manipulation.
// The smallest rotation can be efficiently calculated by comparing rotations.
// Case 2: k > 1:
// //Use rotations for k = 1 to find the smallest lexicographical order.
// Use sorting for k > 1 to directly rearrange characters.
// Complexities:
// k = 1: O(n^2) time and O(n) space.
// k > 1: O(n log n) time and O(1) space.

// Sort the string, as we can rearrange the first k characters freely to achieve the smallest lexicographical order.
 if (k == 1) {
            string smallest = s;
            int n = s.size();
            for (int i = 0; i < n; i++) {
                // Generate all rotations and find the smallest
                s = s.substr(1) + s[0];
                if (s < smallest) {
                    smallest = s;
                }
            }
            return smallest;
        } else {
            // Directly sort the string for k > 1
            sort(s.begin(), s.end());
            return s;
    }
    }
};