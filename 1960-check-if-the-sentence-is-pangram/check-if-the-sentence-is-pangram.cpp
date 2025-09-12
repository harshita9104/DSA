class Solution {
public:
    bool checkIfPangram(string sentence) {
        int arr[26] = {0};  // Track if each letter 'a' to 'z' is seen

        for (auto ch : sentence) {
            arr[ch - 'a'] = 1;  // Mark the letter as seen
        }

        for (int i = 0; i < 26; i++) {
            if (arr[i] == 0) {
                return false;  // If any letter is missing, it's not a pangram
            }
        }

        return true;  // All letters found

    }
};