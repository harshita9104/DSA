class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //prefix sum means ab tk jitne bhi elem aaye unka sum, 
        // ab exactly k, ka sum mila ya nhi vo pta krne k liye
        //hm ek hash map rkhenge jo sum or unka count store krega, 
        //ye hash map ye btayega ki let say a num s , s ka sum arr m 2 baar occur ho gya h 
        //is hash map m i will look ki prefixsum - k , exist krta h ya nhi or krta h to kitni baar krta h 
        //lets say prefixsum is 7 and k =3
        //rem sum = 7-3 =4 so i will look 4 in hashmap and if i find 4 ->2 , it means 2 baar 4 ki occurence hai
        //it means jo sum mujhe chahiye 3 uski occurence bhi alg tareeke se 2 baar nikali ja skti hai is subarr m
        unordered_map<int, int> mp;
        int prefixsum = 0;
        int cnt =0;
        mp[0] =1;//it means 0 subarr sum bhi ek baar aata hai jab hm empty subarr lete h
        for(int i = 0; i<nums.size(); i++){
            prefixsum += nums[i];
            int rem = prefixsum - k;
            //ye rem jitni baar occur hua h utni baar hi k sum bhi occur hoga is subarr m 
            cnt += mp[rem];
            mp[prefixsum]++;

        }
        return cnt;
    }
};