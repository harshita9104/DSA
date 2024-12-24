//leetcode 268
//Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
// Example 1:

// Input: nums = [3,0,1]
// Output: 2
// Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
//brute force
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() ;
        //mistake
        //declare the flag variable inside for loop as everytime it has iterated through the array checking for  a number it needs to be reset to 0 for checking for another number i. 
        for(int i = 1; i<=n; i++){
            int flag = 0;
            for(int j = 0; j<nums.size(); j++){
                if(nums[j] == i){
                    flag = 1;
                    break;

                }

            }
            if(flag == 0){
                return i;
            }
        }
        return 0;
    }
};
//better - use hashing
//optimal 
//1st method calculate sum 
//calculating sum may lead to overflow when number is huge.

class Solution {
public:

    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        int sum2= 0;
        for(int i = 0; i<n; i++){
            sum2 += nums[i];
        }

            
        return sum - sum2;
    }
};
//2nd method perform XOR operation(a^a = 0, a^0 = a) bw the numbers from 1 to n and the elements of arr the missing number in arr will be returned .
class Solution {
public:


    int missingNumber(vector<int>& nums) {
       int n = nums.size();
        int xor1 = 0;
        int xor2 = 0;

        // XOR all array elements
        for(int i = 0; i < n; i++){
            xor1 = xor1 ^ nums[i];
        }

        // XOR all numbers from 0 to n
        for(int i = 0; i <= n; i++){
            xor2 = xor2 ^ i;
        }

        // The missing number is the XOR of the above two results
        return xor1 ^ xor2;
    }
};