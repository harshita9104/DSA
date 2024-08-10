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

    //function to get the kth smallest
    //form a max heap of size k , the top elm will be the kth smallest 
    //considering that below it ar elem which are smaller than it in arr
    // so the top elem in a k size heap is kth smallest
    int kthsmallest(long long A[],long long N, long long k){
        priority_queue<int> maxheap;
        for(int i = 0; i< N; i++){
            maxheap.push(A[i]);
            if(maxheap.size() >k){
                maxheap.pop();
            }
        }
        return maxheap.top();
    }
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        int first = kthsmallest(A,N,K1);  
        int second = kthsmallest(A,N, K2);
        long long sum = 0;
        for(int i = 0; i<N; i++){
            if(A[i] > first && A[i] < second){
                sum += A[i];
            }
        }
        return sum;

    }