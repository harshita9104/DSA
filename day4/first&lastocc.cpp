// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].


class Solution {
public:
int firstOcc(vector<int> &arr ,int traget,int len){
        int low=0;
        int high=len-1;
        int mid;
        int ans =-1;

        while(low<=high){
            mid=low+(high-low)/2;
           //even if we get our target elem we dont know it is first occ or not
           //so this can be a possible answer but i have to look for more smaller elem than this to find if it is eq to target or not, so reduce to left half.
            if(arr[mid]==traget){
                ans=mid;
                high=mid-1;
            } else if(traget>arr[mid]){
                low=mid+1;
            }else if(traget<arr[mid]){
                high=mid-1;
            }

        }

        return ans;    
    }
    int lastOcc(vector<int> &arr ,int traget,int len){
        int low=0;
        int high=len-1;
        int mid;
        int ans =-1;

        while(low<=high){
            mid=low+(high-low)/2;
           //even if we get our target elem we dont know it is last occ or not
           //so this can be a possible answer but i have to look for more greater elem than this to find if it is eq to target or not, so reduce to right half.
            if(arr[mid]==traget){
                ans=mid;
                low=mid+1;
            } else if(traget>arr[mid]){
                low=mid+1;
            }else if(traget<arr[mid]){
                high=mid-1;
            }

        }

        return ans;    
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int len = nums.size();
        int temp1 = firstOcc(nums,target,len);
        int temp2= lastOcc(nums,target,len);
        ans.push_back(temp1);
        ans.push_back(temp2);

        return ans ;
    }
};