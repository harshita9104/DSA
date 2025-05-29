class Solution {
public:
    bool closeStrings(string word1, string word2) {
        //upon observation for two words to be close after performing the given operations
        //it is imp tht thw size of the words be eq as size cannot be changed by given operations 
        if(word1.size() != word2.size()){
            return false;
        }
        //and the unique elem in word1 shd be same as unique elem in word2 as a new elem cannot be added after given operations
        //so we will use set to store the unique char in both words then compare and check if both sets are eq then these strings are close 
        //You should check:

// That the unique characters in both strings are the same.

// That the set of frequencies in word1 and word2 match (this is where the issue lies). We need to make sure that both strings have the same frequency distribution (but they may have different characters with the same frequency).


 // Step 1: Count the frequency of each character in both words
        unordered_map<char, int> mp1, mp2;
        for (char &ch : word1) {
            mp1[ch]++;
        }
        for (char &ch : word2) {
            mp2[ch]++;
        }

        // Step 2: Check if both words have the same unique characters
        set<char> set1(word1.begin(), word1.end());
        set<char> set2(word2.begin(), word2.end());
        if (set1 != set2) {
            return false;  // The sets of unique characters must be identical
        }

        // Step 3: Check if both words have the same frequency distribution
        vector<int> freq1, freq2;
        for (auto &entry : mp1) {
            freq1.push_back(entry.second);
        }
        for (auto &entry : mp2) {
            freq2.push_back(entry.second);
        }

        // Sort both frequency vectors to compare them
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        // Step 4: If the frequency distributions match, return true; else false
        return freq1 == freq2;

    }
};