class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        //its given that no. of string in nums are n and length of those strings will be n
        //so hm index 0 par 0th index wali string k index 0 par jo hai uska ulta rakh skte taaki uske similar to kabhi nhi hogi hmari string
        //similarly sari strings se diff karne k liye har index par aese hi kar skte
        int j =0;
        string result = "";
        for(int i =0; i<nums.size(); i++){
            string temp = nums[i];
            if(temp[i] == '0'){//check only ith char for ith index 
                result += "1";
            }else{
                result += "0";
            }

        }
        return result;
    }
};