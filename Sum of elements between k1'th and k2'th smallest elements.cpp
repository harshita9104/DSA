// Given an array A[] of N positive integers and two positive integers K1 and K2. Find the sum of all elements between K1th and K2th smallest elements of the array. It may be assumed that (1 <= k1 < k2 <= n).

 

// Example 1:

// Input:
// N  = 7
// A[] = {20, 8, 22, 4, 12, 10, 14}
// K1 = 3, K2 = 6
// Output:
// 26
// Explanation:
// 3rd smallest element is 10
// 6th smallest element is 20
// Element between 10 and 20 
// 12,14. Their sum = 26.

class Solution {
  public:
  // kth smallest nikalne ke liye max-heap of size k
  long long findksmallest(long long A[], long long N, long long K){
      priority_queue<long long> maxheap;
      for(long long i = 0; i < N; i++){
          maxheap.push(A[i]);
          if(maxheap.size() > K){
              maxheap.pop();
          }
      }
      return maxheap.top(); // top pe kth smallest hoga
  }
  
  long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
      // k1th aur k2th smallest find karo
      long long first = findksmallest(A, N, K1);
      long long second = findksmallest(A, N, K2);
      long long sum = 0;
      for(long long i = 0; i < N; i++){
          // between k1th and k2th (exclusive)
          if(A[i] > first && A[i] < second){
              sum += A[i];
          }
      }
      return sum;
  }
};
