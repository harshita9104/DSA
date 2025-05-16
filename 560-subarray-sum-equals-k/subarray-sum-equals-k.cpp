class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> subNum;
        // This algorithm needs to have total of subarray and frequency of the total. We will use HashMap. Key is total and value is frequency.


        subNum[0] = 1;
        int total = 0, count = 0;

        for (int n : nums) {
            total += n;
//Every time we calculate total - k and search for the HashMap
            if (subNum.find(total - k) != subNum.end()) {
                count += subNum[total - k];
            }

            subNum[total]++;
        }

        return count;
    }
};