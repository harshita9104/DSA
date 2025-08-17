// Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 

// Examples:

// Input: arr[] = [4, 3, 2, 6]
// Output: 29
// Explanation: We can connect the ropes in following ways.
// 1) First connect ropes of lengths 2 and 3. Which makes the array [4, 5, 6]. Cost of this operation 2 + 3 = 5. 
// 2) Now connect ropes of lengths 4 and 5. Which makes the array [9, 6]. Cost of this operation 4 + 5 = 9.
// 3) Finally connect the two ropes and all ropes have connected. Cost of this operation 9 + 6 =15. Total cost is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. 
// Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first (we get three rope of 3, 2 and 10), then connect 10 and 3 (we get two rope of 13 and 2). Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.
// Input: arr[] = [4, 2, 7, 6, 9]
// Output: 62 
// Explanation: First, connect ropes 4 and 2, which makes the array [6, 7, 6, 9]. Cost of this operation 4 + 2 = 6. 
// Next, add ropes 6 and 6, which results in [12, 7, 9]. Cost of this operation 6 + 6 = 12.
// Then, add 7 and 9, which makes the array [12,16]. Cost of this operation 7 + 9 = 16. And
// finally, add these two which gives [28]. Hence, the total cost is 6 + 12 + 16 + 28 = 62.
// Input: arr[] = [10]
// Output: 0
// Explanation: Since there is only one rope, no connections are needed, so the cost is 0.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 104

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // The greedy algorithm for this problem is to always connect the two smallest ropes, sum their cost, and push the new rope back into the min-heap.
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(int &len : arr){
            minheap.push(len);
        }
        int cost =0;
       //sabse choti do ropes uthao, unko jodo, cost mein add karo, fir nayi rope heap mein daal do
// ye process tab tak repeat karo jab tak ek hi rope bach jaye
// total cost return karo
//2 smallest rope ko jod kar vapis heap m dalna h taaki ab ye nayi rope dusri rope se combine ho paye
//aisa tab tk karna h jab tak hmare pas 1 single rope nhi bna lete
while(minheap.size() > 1){
    int rope1 = minheap.top();
    minheap.pop();
    int rope2 = minheap.top();
    minheap.pop();
    int sum = rope1 + rope2;//curr processing 2 ropes ka sum
    cost += sum;
    minheap.push(sum);//jo nayi rope bnayi usko heap m daalo taaki ye nayi rope kisi or piece of rope se connect ho paye 
}
        return cost;
    }
};
