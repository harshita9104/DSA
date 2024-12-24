class Solution {
public:
     vector<vector<int>> result;
    void twosum(vector<int> &nums, int target, int i , int j ){
        while(i<j){
            if(nums[i] + nums[j] <target){
                i++;
            }else if(nums[i] + nums[j] > target){
                j--;
            }else{
                //to avoid duplicates while finding the numbers jab tak consecutive number same h pointer move karte raho 
                while(i<j && nums[i] == nums[i+1]) i++;
                while(i<j && nums[j] == nums[j-1])j--;
                result.push_back({-target, nums[i], nums[j]});
                i++;
                j--;
            }
        }
       
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
       
        if(n < 3){
            return {};
        }
        sort(nums.begin(), nums.end());
        //fixing one elem = n1
        for(int i = 0; i< n; i++){
            //same n1 k liye dobara find na kare isliye
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int n1 = nums[i];
            int target = -n1;
            //target mil gya ab rem arr par two sum lgado taaki baaki k dono elem bhi mil jae
            twosum(nums,target, i+1, n-1);

        }
        return result;
    }
};