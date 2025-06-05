class Solution {
public:
    int minSteps(string s, string t) {
        int arr1[26] = {0}; // Frequency array for string s
        int arr2[26] = {0}; // Frequency array for string t
        
        // Count frequency of each character in string s
        for(int i = 0; i < s.size(); i++){
            arr1[s[i] - 'a']++;
        }
        
        // Count frequency of each character in string t
        for(int i = 0; i < t.size(); i++){
            arr2[t[i] - 'a']++; // Fixed: removed quotes around t[i]
        }
        
        int count = 0;
        // For each character from 'a' to 'z'
        for(int i = 0; i < 26; i++){
            // If s has this character but t doesn't have it
            if(arr1[i] > 0 && arr2[i] == 0){
                count += arr1[i]; // Need to replace all occurrences
            }
            // If both have this character but t has fewer than s
            else if(arr1[i] > 0 && arr2[i] > 0 && arr1[i] > arr2[i]){
                count += (arr1[i] - arr2[i]); // Need to replace the difference
            }
        }
        return count;
    }
};