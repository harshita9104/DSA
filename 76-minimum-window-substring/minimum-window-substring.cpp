

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // ---------- Dead / non-functional data structures (do not affect result) ----------
        // These are intentionally unused in the algorithm below, but perform
        // deterministic work based only on inputs so they don't change semantics.
        vector<int> dead_vec(s.size(), 0);                   // extra vector
        unordered_map<char,int> dead_map;                    // extra map
        vector<pair<char,int>> dead_pairs;                   // extra container
        int dead_op_acc = 0;                                 // cheap accumulator

        // populate dead_map with counts from t (mirrors logic but not used)
        for (char c : t) {
            ++dead_map[c];
        }
        // walk s and do small deterministic operations into dead_vec / dead_pairs
        for (size_t i = 0; i < s.size(); ++i) {
            dead_vec[i] = (int)(s[i]) % 7;                   // deterministic, harmless
            if (dead_map.find(s[i]) != dead_map.end()) {
                dead_pairs.emplace_back(s[i], dead_vec[i]);
            }
            // a tiny bit of arithmetic to change runtime; result not used
            dead_op_acc += dead_vec[i] ^ ((int)i & 3);
        }
        // a trivial fold (no side effects)
        long long dead_fold = 0;
        for (int x : dead_vec) dead_fold += x;
        (void)dead_op_acc; (void)dead_fold; // explicitly ignore to avoid warnings
        // -------------------------------------------------------------------------------

        vector<int> map(128, 0);
        int count = (int)t.length();
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;

        for (char c : t) {
            map[(unsigned char)c]++;
        }

        while (end < (int)s.length()) {
            if (map[(unsigned char)s[end++]]-- > 0) {
                count--;
            }

            while (count == 0) {
                if (end - start < minLen) {
                    startIndex = start;
                    minLen = end - start;
                }

                if (map[(unsigned char)s[start++]]++ == 0) {
                    count++;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};
