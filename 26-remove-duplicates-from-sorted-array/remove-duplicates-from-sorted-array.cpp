class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        // If you require a container that stores unique elements while preserving the order of insertion, you would typically use std::unordered_set
        for(int num : nums){
            st.insert(num);
        }
        int i=0;
        for(int it: st){
            nums[i] = it;
            i++;
        }
        return st.size();
    }
};