class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        //find all occurences of a and b in s 
        //.find(pattern, pos) is a method which 
        //text.find(pattern, pos) parameters:
// pattern: What to search for
// pos: Starting position for the search (where to begin looking)
        // Find all occurrences of 'a' in s
        vector<int> occof_a;
        size_t pos = 0;
        while ((pos = s.find(a, pos)) != string::npos) {
            occof_a.push_back(pos);
            pos++; // Move by 1 to find overlapping occurrences
        }
        
        // Find all occurrences of 'b' in s
        vector<int> occof_b;
        pos = 0;
        while ((pos = s.find(b, pos)) != string::npos) {
            occof_b.push_back(pos);
            pos++; // Move by 1 to find overlapping occurrences
        }
        
        vector<int> result;
        
        // For each occurrence of 'a', check if there's a valid 'b' within distance k
        for (int i = 0; i < occof_a.size(); i++) {
            for (int j = 0; j < occof_b.size(); j++) {
                // Check if absolute distance is <= k
                if (abs(occof_a[i] - occof_b[j]) <= k) {
                    result.push_back(occof_a[i]);
                    break; // Found one valid 'b', no need to check others for this 'a'
                }
            }
        }
        
        return result;
    }
};