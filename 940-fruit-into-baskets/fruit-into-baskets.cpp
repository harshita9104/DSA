class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> st;  // Map to count the number of each fruit type in the current window
        int i = 0; // Start of the sliding window
        int j = 0; // End of the sliding window
        int longest = 0; // To store the maximum number of fruits we can collect
        
        while (j < fruits.size()) {
            st[fruits[j]]++;  // Include current fruit in the basket (or increase its count)

            // Case 1: We have less than 2 fruit types → valid window
            // if (st.size() < 2) {
            //     j++;  // Just expand the window
            // }

            // Case 2: Exactly 2 types of fruits → update the max length
            if (st.size() == 2 || st.size() == 1) {
                longest = max(longest, j - i + 1);  // Valid window, update max
                // j++;  // Expand window
            }

            // Case 3: More than 2 types → invalid window, need to shrink from the left
            else if (st.size() > 2) {
                while (st.size() > 2) {
                    st[fruits[i]]--;  // Remove the fruit at the left end of the window
                    if (st[fruits[i]] == 0) {
                        st.erase(fruits[i]);  // Completely remove if count is 0
                    }
                    i++;  // Move the left pointer to shrink the window
                }
                // j++;  // Expand window after shrinking
            }
            j++;
        }

        return longest;  // Return the maximum length of valid window found
    }
};
