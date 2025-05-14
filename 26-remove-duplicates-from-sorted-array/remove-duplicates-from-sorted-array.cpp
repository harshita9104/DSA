class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        int j=1;
        //curr p rhke chcek kro vo prev k eq to nhi h agar nhi h to hi nums[j] m vo val daalo kyuki vo uniqe hai agar equal hota to kuch mt karo aage badh jaao
        for(int i = 1; i<n; i++){
            if(nums[i] != nums[i-1]){
                nums[j] = nums[i];
                j++;
            }else{
                continue;//aage badho loop m kuch nhi krna
            }
        }
        return j;//this is pointing at the last unique elem in nums
    }
};