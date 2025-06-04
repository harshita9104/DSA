class Solution {
public:
    string sortVowels(string s) {
        // Step 1: Define all vowels (both uppercase and lowercase)
        set<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        
        // Step 2: Find all indices where vowels are located
        vector<int> index;
        for(int i = 0; i < s.size(); i++){
            if(vowels.find(s[i]) != vowels.end()){
               index.push_back(i); // Store index of vowel position
            }
        }
        
        // Step 3: Extract vowels from their positions and sort them
        vector<char> vowelChars;
        for(int i = 0; i < index.size(); i++){
            vowelChars.push_back(s[index[i]]); // Extract vowel characters
        }
        sort(vowelChars.begin(), vowelChars.end()); // Sort by ASCII values
        
        // Step 4: Place sorted vowels back into their original positions
        for(int j = 0; j < index.size(); j++){
            s[index[j]] = vowelChars[j]; // Replace with sorted vowel
        }
        
        return s;
    }
};