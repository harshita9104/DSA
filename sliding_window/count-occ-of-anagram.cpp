// ### Simple Explanation of Optimized Solution

// 1. **Optimization Over Brute Force:**
//    - The brute force approach would involve checking all possible substrings of `s2` with length equal to `s1` and verifying if any of them is a permutation of `s1`. This would be very inefficient with a time complexity of O((n-m+1)*m*log(m)), where n is the length of `s2` and m is the length of `s1`.
//    - To optimize this, we use the **Sliding Window** technique combined with a **HashMap** to keep track of character frequencies. This allows us to efficiently check for permutations in a fixed-size window.

// 2. **Data Structures and Algorithms Used:**
//    - **HashMap (unordered_map):** To store the frequency of characters in `s1`.
//    - **Sliding Window:** To traverse `s2` with a window size equal to the length of `s1`.

// 3. **Why These Structures and Techniques:**
//    - The **HashMap** allows for O(1) average time complexity for insertions and lookups, making it efficient to track and update character counts.
//    - The **Sliding Window** ensures we only traverse the string once, resulting in an O(n) time complexity.

// ### Detailed Explanation of Optimized Approach

// Here's how you can explain the optimized approach step-by-step to an interviewer:

// 1. **Initialization:**
//    - First, create a HashMap to store the frequency of each character in `s1`.
//    - Count the distinct characters in `s1` and store this count.

// 2. **Sliding Window Setup:**
//    - Initialize two pointers `i` and `j` to represent the start and end of the sliding window.
//    - Set the window size `k` to be the length of `s1`.

// 3. **Sliding Window Traversal:**
//    - Traverse the string `s2` using the end pointer `j`.
//    - For each character in `s2`, decrement its frequency in the HashMap if it exists.
//    - If the frequency of a character becomes zero, decrement the distinct character count.

// 4. **Window Size Check:**
//    - If the window size (difference between `j` and `i` plus one) is less than `k`, move the end pointer `j` to the right.
//    - If the window size is equal to `k`, check if the distinct character count is zero. If yes, it means a permutation of `s1` is found in `s2`, so return `true`.

// 5. **Slide the Window:**
//    - If the distinct character count is not zero, slide the window by moving the start pointer `i` to the right.
//    - Before moving `i`, increment the frequency of the character at `i` in the HashMap if it exists. If the frequency becomes one, increment the distinct character count.
//    - Move both pointers `i` and `j` to the right and repeat the process.

// 6. **Return Result:**
//    - If no permutation is found after traversing `s2`, return `false`.

// ### Example Explanation with Output

// Consider `s1 = "ab"` and `s2 = "eidbaooo"`.

// - **Step-by-Step Process:**
//   1. Initialize the HashMap with frequencies of characters in `s1`: `{'a': 1, 'b': 1}`.
//   2. Set `cnt` to 2 (since there are two distinct characters in `s1`).
//   3. Start with `i = 0` and `j = 0`.
//   4. Traverse `s2`:
//      - At `j = 0`, `s2[j]` is `e`. It is not in the HashMap, so just move `j`.
//      - At `j = 1`, `s2[j]` is `i`. It is not in the HashMap, so just move `j`.
//      - At `j = 2`, `s2[j]` is `d`. It is not in the HashMap, so just move `j`.
//      - At `j = 3`, `s2[j]` is `b`. Decrement its frequency in the HashMap: `{'a': 1, 'b': 0}`. Decrement `cnt` to 1.
//      - At `j = 4`, `s2[j]` is `a`. Decrement its frequency in the HashMap: `{'a': 0, 'b': 0}`. Decrement `cnt` to 0.
//   5. Now the window size is 2, and `cnt` is 0. This indicates a permutation of `s1` is found in `s2`, so return `true`.

// ### Code with Detailed Comments

// ```cpp
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Create a HashMap to store the frequency of each character in s1
        unordered_map<char, int> mp;
        for (auto it : s1) {
            mp[it]++;
        }

        int cnt = mp.size(); // Count of distinct characters
        int i = 0, j = 0; // Initialize the start (i) and end (j) pointers of the window
        int k = s1.size(); // Window size is the length of s1

        // Traverse through s2 with the end pointer j
        while (j < s2.size()) {
            // If the character at j is in the HashMap, decrement its frequency
            if (mp.find(s2[j]) != mp.end()) {
                mp[s2[j]]--;
                // If the frequency becomes zero, decrement the distinct character count
                if (mp[s2[j]] == 0) {
                    cnt--;
                }
            }

            // If the current window size is less than k, move the end pointer j
            if (j - i + 1 < k) {
                j++;
            }
            // If the current window size is equal to k
            else if (j - i + 1 == k) {
                // If the distinct character count is zero, a permutation is found
                if (cnt == 0) return true;
                // Before sliding the window, increment the frequency of the character at i
                if (mp.find(s2[i]) != mp.end()) {
                    mp[s2[i]]++;
                    // If the frequency becomes one, increment the distinct character count
                    if (mp[s2[i]] == 1) {
                        cnt++;
                    }
                }
                // Slide the window by moving both pointers to the right
                i++;
                j++;
            }
        }
        // If no permutation is found, return false
        return false;
    }
};

int main() {
    Solution sol;
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << sol.checkInclusion(s1, s2) << endl; // Output: 1 (true)
    return 0;
}
 