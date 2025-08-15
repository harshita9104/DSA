//Given an array arr[], where each element is at most k away from its target position, you need to sort the array optimally.
// Note: You need to change the given array arr[] in place.

// Examples:

// Input: arr[] = [6, 5, 3, 2, 8, 10, 9], k = 3
// Output: [2, 3, 5, 6, 8, 9, 10]
// Explanation: The sorted array will be 2 3 5 6 8 9 10
// Input: arr[]= [1, 4, 5, 2, 3, 6, 7, 8, 9, 10], k = 2
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// Explanation: The sorted array will be 1 2 3 4 5 6 7 8 9 10
// Don't use the inbuilt sort() function for this question.

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ k < arr.size()
// 1 ≤ arri ≤ 106

//use  a min heap and store upto k+1 elements in it the elem which needs to be at ith position is present 
        //from i to i+k renge in arr and all these elem are in min heap then min heap will give us 
        //the min elem on the top so that we will get the required elem for index i and then we will pop it
        //as it is now at its correct position and it is not required in heap whilewe do i+1 and find elem for other positions

class Solution {
  public:
  //k+1 ka window bana ke min heap mein daalo, har step pe min heap ka top nikaal ke array mein daalo
// jab array ke saare elements heap mein daal diye, to heap mein bache hue elements bhi nikaalo aur array mein daalo (ye array ke last ke elements hain)
// isse array completely sort ho jayega
    void nearlySorted(vector<int>& arr, int k) {
        int i = 0;
        priority_queue<int, vector<int>, greater<int>> minheap;
        // pehle k+1 elements heap mein daalo
        for(int j = 0; j < arr.size(); j++){
            minheap.push(arr[j]);
            // heap ka size k+1 ho gaya to min nikaalo
            if(minheap.size() == k + 1){
                arr[i++] = minheap.top();
                minheap.pop();
            }
        }
        // ab heap mein bache hue elements nikaalo
        while(!minheap.empty()){
            arr[i++] = minheap.top();
            minheap.pop();
        }
    }
};
