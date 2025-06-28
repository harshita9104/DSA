class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int i =0;
       int j =0;
       while(i<=j && j<nums.size()){
        if(j<nums.size() && nums[j] == val)j++;
        if(j<nums.size() && nums[j] != val){
            nums[i] = nums[j];
            i++;
            j++;
        }
        
       }
       return i;
    }
};