class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n<m)return "";
        int substr = INT_MAX;
        int i =0;
        int j =0;
unordered_map<char, int> mp;
        for(char &ch : t){
            mp[ch]++;
        }
//since count has become 0 there may be some extra char in substr for which the map value might have become neg so we can remove those char untill that map value becomes 0 , we will remove those extra char while still maintaining the count 0 as we want to get the min len substr while still having all the char of t in it
int start =0;
        int count = mp.size();
        while (j < s.size()) {
            // If current char is part of t, reduce its count in map
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    count--; // Requirement for this char is fulfilled
                }
            }

            // If all characters are matched, try shrinking the window
            while (count == 0) {
                // Update minimum substring length and starting index
                if (j - i + 1 < substr) {
                    substr = j - i + 1;
                    start = i;
                }

                // Try to remove s[i] from window
                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0) {
                        count++; // Now missing one char, so increase count
                    }
                }
                i++; // Shrink from the left
            }

            j++; // Expand window from the right
        }

        // If no valid window found
        if (substr == INT_MAX) return "";

        // Return the minimum window substring
        return s.substr(start, substr);
    }
};
