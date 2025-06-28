class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //question is how we will figure out that two string are anagram 
        //if we sort all the strings then all the anagrams will become one string becoz they all consist of same char in same number ,
        // and then we will store the anagram strings corresponding to their sorted val in map to segregate them from other set of anagrams
        unordered_map<string,vector<string>> mp;

        for(int i =0; i<strs.size(); i++){
             string temp = strs[i];//temp ko sort karenge 
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }
        //ab map m sorted val k correspoding uske anagrams ka vector hai to map m iterate karke ye vector ko result m daaldo
        vector<vector<string>> result;
        for(auto  it : mp){
            result.push_back(it.second);//iterator se map ki value ko access kro 
        }
        return result;
    }
};