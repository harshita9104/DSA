class Solution {
public:
   int strStr(string haystack, string needle) {
    int i = 0; // pointer for haystack
    int j = 0; // pointer for needle
    int ans = -1;

    while(i < haystack.size()) {
        // Try to match needle[j] with haystack[i]
        if(haystack[i] == needle[j]) {
            if(j == 0) {
                ans = i; // record possible match start index
            }
            i++;
            j++;
            // if full match is found
            if(j == needle.size()) {
                return ans;
            }
        } else {
            // mismatch occurred, reset j and move i accordingly
            if(j > 0) {
    // Had a partial match, restart from next char after where match began
               i = ans + 1;
            } else {
    // No match started, just move forward
               i++;
            }
            j = 0;      // Reset needle pointer
            ans = -1;   // Clear current match starting index
        }
    }

    return -1;
}

};