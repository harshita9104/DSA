class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //string p m jo char aa rhe or unki freq ko map m store krlo
        //jaise window m slide kr rhe 
        //mp[char]-- karte jaao or window size hit krte hai hi sare char ki freq 0 ho gyi it means anagram mil gya ab pta kaise chlega ki map m sari value 0 hogyi kya
        //map ki size jitna ek count var bnalo, jaise hi koi map[char] i val 0 hoye, count-- kardo , agar kisi window m count =0 ho gya it means sare char ki freq 0 ho gyi h
        //jab window slide krenge to map[nums[j]]-- , kyuki ye window m aagya h
        //or map[nums[i]]++, kyuki ye window se bahar jaa chuka h

        unordered_map<char, int> mp;
        
        // Step 1: Count frequencies of each character in 'p'
        for (char &ch : p) {
            mp[ch]++;
        }

        int count = mp.size(); // Number of unique characters to match
        int k = p.size(); // Window size
        int i = 0, j = 0;
        vector<int> res;

        while (j < s.size()) {
            // Step 2: Process current character s[j]
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    count--; // One character frequency matched
                }
            }

            // Step 3: When window size is less than k, just move j
            if (j - i + 1 < k) {
                j++;
            }
            // Step 4: When window size hits k
            else if (j - i + 1 == k) {
                if (count == 0) {
                    res.push_back(i); // Valid anagram window
                }

                // Now slide the window: remove s[i] and move i++
                if (mp.find(s[i]) != mp.end()) {
                    if (mp[s[i]] == 0) {
                        count++; // We're breaking a previously matched character
                    }
                    mp[s[i]]++; // Put the character back
                }

                i++;
                j++;
            }
        }

        return res;
    }
};
