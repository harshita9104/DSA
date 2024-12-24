class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //sorted given h to or optimise krna hoga
        //2 pointer lelo ek starting m or ek end m 
        int i = 0;
        int n = numbers.size();
        int j = n-1;
        while(i<j){
           if(numbers[i] + numbers[j] < target){
            // to value inc karne k liye i pointer ko move kare aage
            i++;

           } else if(numbers[i] + numbers[j]> target){
            // to value dnc karne k liye j pointer ko move kare piche
            j--;

        }else{
            return{i+1, j+1};
        }


    }
    return {};
    }
};