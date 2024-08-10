// Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally.

// Example 1:

// Input:
// n = 7, k = 3
// arr[] = {6,5,3,2,8,10,9}
// Output: 2 3 5 6 8 9 10
// Explanation: The sorted array will be
// 2 3 5 6 8 9 10
//Function to return the sorted array.
    //standing at ith position we will look for an elem within range of k which shd be at ith position for the arr to be sorted
    //hm ith index p khade hoke  k range tak k elem minheap m daalenge..
    //sort karna hai smallest phle hona chahiye , heap k top p , k range m se smallest elem hai, to vahi phle aana chahiye to usko ans vector m push karke minheap.top kardo
    //end m jab minheap m elem bach jaate hai to ek ek karke uske top k elem ko ans m daalke pop kardo
    //minheap k top m hmesha min elem hota hai to we will get the elm in sorted order only
    vector <int> nearlySorted(int arr[], int num, int K){
        priority_queue<int, vector<int> , greater<int>> minheap;
        vector<int> ans;
        for(int i = 0; i<num ; i++){
            minheap.push(arr[i]);
            if(minheap.size() > K){
                ans.push_back(minheap.top());
                minheap.pop();
            }
        }
        while(!minheap.empty()){
           ans.push_back(minheap.top());
                minheap.pop();
        }
        return ans;
    }