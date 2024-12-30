class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i< n; i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);

        }
        for(auto it: mp){
            result.push_back(it.second);
        }
        return result;
    }
};