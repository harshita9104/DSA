class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        int count = 0;
        
        // Check all possible substrings
        for(int i = 0; i < s.size(); i++){
            int vowels = 0;
            int consonants = 0;
            
            // Build substring starting from index i
            for(int j = i; j < s.size(); j++){
                // Add current character to our count
                if(vowel.find(s[j]) != vowel.end()){
                    vowels++;
                } else {
                    consonants++;
                }
                
                // Check if current substring s[i...j] is beautiful
                if(vowels == consonants && (vowels * consonants) % k == 0){
                    count++;
                }
            }
        }
        
        return count;
    }
};