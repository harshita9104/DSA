class Solution {
public:
 //we will sort the strings, all the anagrams will be converted to a single string after sorting and to group all these anagrams together, we will use a map which will map the sorted string with their corresponding family of anagrams.
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
