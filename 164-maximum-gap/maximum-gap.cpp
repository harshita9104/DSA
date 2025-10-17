class Solution {
public:
    int maximumGap(vector<int>& nums) {
        //Size of the array 
        int n=nums.size();
        //return 0 if array size is less than 2 
        if(n<2) return 0;
        
        int max=0;
        //Take a vector to store all the gaps 
        vector<int>vec;

        //Sort the array 
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-1;i++){
            //Store gap in vector
            vec.push_back(nums[i+1]-nums[i]);
            //Find maximum gap
            max=std::max(max, vec[i]);
        }

        //Display the max gap
        return max;
    }
};