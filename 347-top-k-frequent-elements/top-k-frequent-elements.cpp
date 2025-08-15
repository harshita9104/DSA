class Solution {
public:
typedef pair<int, int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i =0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        //hme har int ka count mil gya
        //heap m count, elem store krenge kyuki hme sabse jyada k most freq elem chahiye to jo less freq h usse remove krna pdega count of elem ko pair m phle rkhenge
        //or min count ko htana h to min heap bnega taki min top pr ho baad m remove ho jae

        priority_queue<p, vector<p>, greater<p>> minheap;
        for(auto it : mp){
            minheap.push({it.second, it.first});
            if(minheap.size() > k){
                minheap.pop();
            }
        }
        vector<int> result;
        while(!minheap.empty()){
            result.push_back(minheap.top().second);
            minheap.pop();
        }
        return result;
    }
};