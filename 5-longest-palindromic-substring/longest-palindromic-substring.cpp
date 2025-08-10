class Solution {
public:
// //Transform the string by adding # between characters!
// Use Manacher's algorithm to expand palindromes efficiently!
// Keep track of the center and right boundary to speed up calculations!
// Find the longest palindrome and extract it from the original string!
    string longestPalindrome(string s) {
        string t = "#";
        for(char &c : s) t += c, t += "#";
        int n = t.size(), c = 0, r = 0, max1 = 0, curr = 0;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            int mirror = (2*c) - i;
            if(i<r) arr[i] = min(r-i,arr[mirror]);
            while(i+arr[i]+1<n && i-arr[i]-1>=0 && t[i+arr[i]+1]==t[i-arr[i]-1]) arr[i]++;
            if(i+arr[i] > r) r = i+arr[i], c = i;
            if(arr[i]>max1) max1 = arr[i], curr = i;
        }
        return s.substr((curr-max1)/2, max1);
    }
};