class Solution {
public:
    string solve(set<string>& unique, string temp, int index, int n){
        // Base case: we've built a complete string of length n
        if(index == n){
            // If this string is NOT in the set, we found our answer!
            if(unique.find(temp) == unique.end()){
                return temp;
            }
            return ""; // This string exists, return empty to indicate failure
        }
        
        // Try adding '0' to current string
        string result = solve(unique, temp + "0", index + 1, n);
        if(result != "") return result; // If we found answer, return it
        
        // Try adding '1' to current string  
        result = solve(unique, temp + "1", index + 1, n);
        return result; // Return result (either found string or empty)
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> unique(nums.begin(), nums.end());
        int n = nums[0].size();
        string temp = "";
        return solve(unique, temp, 0, n);
    }
};