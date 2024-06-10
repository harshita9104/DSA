// BS-7. Find out how many times array has been rotated

int findKRotation(int nums[], int n) {
	   //find the min elem 
	   //which is the point of rotation 
	   //its index will be the answer
        
        int low = 0; int high = n-1;
        int mid = low+(high - low)/2;
         int ans = INT_MAX;
         int index = -1;
        while(low<=high){
           
            mid = low+(high - low)/2;
            if(nums[low]<= nums[mid]){
                //left sorted
                //mistake - take the min of the ans 
               // ans = min(ans,nums[low]);
               //way to get the index of the min elem
               //nums[low] will replace prev ans if it is less than it so instead of using min 
               //we can put this condn and also get the index
               if(nums[low]<ans){
                   ans = nums[low];
                   index = low;
               }
                low = mid+1;
            }else{
                //right sorted 
                //mistake store the elem not the index
                //ans = min(ans,nums[mid]);
                if(nums[mid]<ans){
                    ans = nums[mid];
                    index=mid;
                }
                high = mid-1;
            }
        }
        return index;
	}