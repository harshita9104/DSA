// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

// An integer a is closer to x than an integer b if:

// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b
 

// Example 1:

// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // heap m abki baar vo key jaiske basis p sorting hogi vo hoga abs diff of x and arr[i], so we will store a pair in heap and sort on basis of abs diff, kyuki hme jyada diff wale elem ko udana hai to they should be at top of heap so we will form a maxheap, and size of heap will be k
        priority_queue<pair<int, int>>maxheap;
        for(int i = 0; i< arr.size(); i++){
            maxheap.push(make_pair(abs(x-arr[i]), arr[i]));
            if(maxheap.size()> k){
                maxheap.pop();
            }
        }
        vector<int> ans;
        while(!maxheap.empty()){
            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }