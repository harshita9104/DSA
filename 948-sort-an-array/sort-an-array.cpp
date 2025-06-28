class Solution {
public:
 void conquer(vector<int> &nums, int mid, int s, int e){
            vector<int> merged(e-s+1);
            int idx1 = s;//to keep track of 1st sorted arr
            int idx2 = mid+1;//to keep track of 2nd sorted arr
            int x =0;//keep track of merged 
            while(idx1 <= mid && idx2 <= e){
                if(nums[idx1] <= nums[idx2]){
                    merged[x++] = nums[idx1++];
                }else{
                     merged[x++] = nums[idx2++];
                }
            }
            while(idx1 <= mid){
                merged[x++] = nums[idx1++];
            }
            while(idx2 <= e){
                merged[x++] = nums[idx2++];
            }

            for(int i =0, j = s; i< merged.size(); i++, j++){
                nums[j] = merged[i];
            }
        };
void divide(vector<int> &nums, int s, int e){
            int mid = s +(e-s)/2;
            //ab recursively call karke divide kro actual m divide nhi hoga nums bas pointers move honge s to mid ek arr or mid+1 to e - 2nd arr
            if(s>=e)return;//BC- ye tab hoga jab arr m ek hi elem bacha h or ek elem sorted hota h apne aap m
            divide(nums, s, mid);
            divide(nums, mid+1, e);
            conquer(nums, mid, s,e);
        };
    vector<int> sortArray(vector<int>& nums) {
        

        //merge sort - divide and conquer
       
        
        int s =0;
        int n = nums.size();
        int e = n-1;
        divide(nums,0,n-1);
        return nums;

    }
};