class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //using 2 pointer
        //since the current arr is sorted and when we square these values they will become pos so the largest values will be present on the edges of the given arr so we palce our pointers on the left most and right most elem 
        //and we will start iterating from the last 
        //left or right pointer ki abs val k sq ko compare karo greater ko i par place kro or i-- hoga ,
        //or jo greter aaya tha vo wal pointer ek shift krega
        vector<int> res(nums.size());
        int left = 0;
        int n = nums.size();
        int right =  n-1;
        for(int i = n-1; i>= 0; i--){
            if(abs(nums[left]) > abs(nums[right])){
                res[i] = nums[left]*nums[left];
                
                left++;//update only tht pointer whose elem is at its right place now 
            }else{
                res[i] = nums[right]*nums[right];
                
                right--;
            }
        }
        return res;
        

    }
};