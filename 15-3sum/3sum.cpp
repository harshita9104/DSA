class Solution {
public:
    vector<vector<int>> result;
    void twosum(vector<int> &nums, int target, int j, int k){
        while(j<k){
         if(nums[j] + nums[k] < target){
            j++;
         }else if(nums[j] +  nums[k] > target){
            k--;
         }else {
            //to avoid duplicates while finding the numbers jab tak consecutive number same h pointer move karte raho 
                while(j<k && nums[j] == nums[j+1]) j++;
                while(j<k && nums[k] == nums[k-1])k--;
                result.push_back({-target, nums[j], nums[k]});
                j++;
                k--;
         }
        }
        
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        //we can think of this problem like this that 3 number need to sum up to 0 so 
        //two number can sum to get neg of rem 1 number
        //so keep one pointer at a number do its neg and find this -number by iterating thr the rem elem of the arr using a while loop with cond j<k as it is given tht pointer i, j, k must point at diff positions 
    // so we can sort the arr first to simplify our serach for two sum of -number in the rem elem of arr 
    //in this we will place j at i+1 and k at n-1 and 
    //then compare the sum of nums[i]+ nums[j] with target which is -nums[i]  , 
    // if this sum is smaller then we need to inc it in order to reach the target so since the arr is sorted so we need to move j++ in order to inc this sum 
    //if the sum is larger then in order to dec this sum move k--
    int n = nums.size();
    if(n<3){
        return {};
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i<n; i++){
        int target = -nums[i];
        if(i>0 && nums[i] == nums[i-1]){
            continue;//this is to avoid ki hm same target ko phirse search n kare arr m kyuki duplicate triplet nhi hone chahiye
        }
        //we are passing the sorted arr the target and from where to start looking for target in toe sum in every iteration
        twosum(nums, target, i+1, n-1);
        
    }
    return result;

    }
};