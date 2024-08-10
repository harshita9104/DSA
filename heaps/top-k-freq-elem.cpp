// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;//map to store number and their corresponding freq together
        for(int i = 0; i<nums.size(); i++){
            mpp[nums[i]]++;//key is nums[i], and second para is freq
        }
        //but in heap to sort on the basis of freq we should have freq first in the pair
        // since we want most freq elem so less freq ko htana hai to vo top p hone chahiye to uske liye min heap banao
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        vector<int> ans;
        for(auto it: mpp){//mistake iterate in map using iterator
            minheap.push(make_pair(it.second,it.first));//freq,elem
             if(minheap.size() > k){
               
                minheap.pop();
            }
            
        }
        while(!minheap.empty()){
           ans.push_back(minheap.top().second);
                minheap.pop();
        }
        return ans;
    }