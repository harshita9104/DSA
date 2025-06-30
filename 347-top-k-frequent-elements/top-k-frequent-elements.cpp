class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //map m elem or unka count store karo
        //map k pairs ko vector m daalo
        //vector ko sort kro
        //top k elem return krdo

        unordered_map<int, int> mp;
        for(int &num : nums){
            mp[num]++;
        }
        int n = nums.size();
        vector<pair<int, int>> dummy(n);
        for(auto const& pair : mp){
            dummy.push_back(pair);
        }
        sort(dummy.begin(), dummy.end(), [](const pair<int, int> &a, pair<int, int> &b){
             return a.second > b.second;//descending order
        });
        vector<int> result;
        for(int i =0; i<k; i++){
            result.push_back(dummy[i].first);
        }
        return result;
    }
};