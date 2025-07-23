class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        vector<bool> used(nums.size(), false);
        int n = nums.size();
         // If the total number of elements is not a multiple of k,
    // it's impossible to divide them into groups of k consecutive numbers.
    if(nums.size() % k != 0) return false;

    // Sort the numbers so we can find consecutive sequences easily.
    sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
           if(used[i] == true)continue;//agar curr elem kisi na kisi subarr m use ho gya h to skip krdo
           int count = 1;//subarr m curr elem ko dala
           used[i] = true;//usko used mark kiya
           int prev = nums[i];//isko store kiya kyuki prev +1 karke iska next cons elem  bnega
           //ab next k-1 elem ko count krke or unko used mark krdo 
           for(int j = i+1; j<nums.size() && count <k; j++){
            //count <k hoga tabhi hm subarr k next elem ko use krne is loop m aayenge
            if(!used[j] && nums[j] ==prev+1){//yani agar ye elem not used hai or apne prev elem se +1 hai tabhi isko subarr m lenge
                used[j] = true;
                count++;
                prev = nums[j];//subarr ka next elem find krne m kaam aayega
            }
           }//jaise hi count>=k  ya elem khtm hogya loop se bahar aajaenge 
           //agar count k k eq nhi hua yani subarr form nhi hui 
           if(count<k)return false;
        }
        return true;
    }
};