class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, vector<int>> mp;
        for(int i =0; i< s.size(); i++){
            mp[s[i]].push_back(i);
        }
        int count =0;
        for(auto index: mp){
            vector<int> arr = index.second;
            int first = arr[0];
        int last = arr[arr.size() -1];
        set<char> unique; 
            // string sub = arr.subarr(1, arr.size()-2);
            for(int i = first+1; i<= last -1; i++){
                unique.insert(s[i]);
            }
            count += unique.size();
        }
        return count;
    }
};