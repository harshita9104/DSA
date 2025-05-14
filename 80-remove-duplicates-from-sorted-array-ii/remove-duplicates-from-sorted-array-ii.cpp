class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 2;
        int n = nums.size();
        if (nums.size() <= 2) return nums.size();

        for(int i = 2; i<n ; i++){
            if(nums[i] != nums[j-2]){//make sure hm jo nums[i] ko add karne wale hai nums[j] par to check krlo ki kahi nums[j-2] k eq na ho nhi to ham 3rd same elem add kardenege nums m which needs to be avoided 
            //or kyuki arr sorted h to sare duplicates sath m h isliye sidhe jha add karne wale hai uske last 2 elem check karlo ki kahi vo next add hone wale elem k equal to nhi
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};