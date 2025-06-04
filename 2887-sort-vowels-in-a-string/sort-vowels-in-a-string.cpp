class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isvowel(char c){
        char ch = tolower(c); // Convert to lowercase for easy comparison
        return ch == 'a'||ch =='e'||ch == 'i'|| ch == 'o'|| ch =='u';
    }
    
    string sortVowels(string s) {
        // Step 1: Count frequency of each vowel in the string
        unordered_map<char, int> mp;
        for(auto &ch : s){
            if(isvowel(ch)){
                mp[ch]++; // Count how many times each vowel appears
            }
        }
        
        // Step 2: Pre-sorted vowel string in ASCII order
        // This acts as our "sorted template" - uppercase vowels come first (ASCII 65-85)
        // then lowercase vowels (ASCII 97-117)
        string temp = "AEIOUaeiou";
        int j = 0; // Pointer to track current position in sorted vowel template
        
        // Step 3: Replace vowels in original string with sorted vowels
        for(int i = 0; i < s.size(); i++){
            if(isvowel(s[i])){ // If current character is a vowel
                
                // Find the next available vowel in sorted order
                while(mp[temp[j]] == 0){ // Skip vowels that are exhausted (count = 0)
                    j++;
                }
                
                // Replace current vowel with the smallest available sorted vowel
                s[i] = temp[j];
                mp[temp[j]]--; // Decrease count of used vowel
            }
        }      
        return s;
    }
};