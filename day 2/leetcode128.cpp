//Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.




 //brute
 
 //this function need to be outside the longestconsecutive function as the there cannot be one function inside a function which is returning something 
    bool ls(vector<int>& nums, int a){
          int n = nums.size();
            for(int i = 0; i<n; i++){
                if(nums[i]==a){
                    return true;
                }
            }
            //after iterating the whole arr if we dont get the element(no true is returned) then return false as the function need to have a bool return statement before it ends.
            return false;
        }
public:

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 1;
        //consider the case when arr is empty 
        if(n==0){
            longest = 0;
        }
//we will pick up one element initially and say it x and keep cnt as 1,now i will linear search in the arr for the element x+1, if it is found then now we will look for the next element so x+1 , and 1 element is added to the seq to cnt+1   
        
        for(int i = 0 ; i<n; i++){
            int x = nums[i];
            //start the count from one , whenever u start from next element in arr  to look for a consecutive element.
            int cnt =1;
            while(ls(nums, x+1)== true){
                x= x+1;
                cnt++;
            }
            //and after the while loop ends that is we have got the sequence and the no. of elements in the seq starting from nums[i] (i.e, cnt)
            //we will look for the longest seq
            longest = max(longest, cnt);

        }
        return longest;
    }

    //better
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int longest = 1;
        int count = 0;
        int lastsmaller = INT_MIN;
        if(nums.size() == 0){
            longest = 0;
        }
        for(int i = 0; i<nums.size(); i++){
            
            
            if(nums[i]-1 == lastsmaller ){
                count++;
                lastsmaller =  nums[i];
            }else if(lastsmaller != nums[i]){
                count = 1;
                lastsmaller =  nums[i];
            }
            longest = max(longest, count);
        }
        return longest;
    }
    