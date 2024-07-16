// We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

// For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
// Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.

 

// Example 1:

// Input: n = 1, k = 1
// Output: 0
// Explanation: row 1: 0
// Example 2:

// Input: n = 2, k = 1
// Output: 0
// Explanation: 
// row 1: 0
// row 2: 01

// Key Observations
//the length of nth row is 2^(n-1) 
//For any symbol in the first half of the n-th row, the corresponding symbol in row 

// n−1 is the same.

// For any symbol in the second half of the n-th row, the corresponding symbol in row  n−1 is flipped (0 becomes 1, 1 becomes 0).
int kthGrammar(int n, int k) {
       int mid = (pow(2,n-1))/2;
       // Base case: if we are at the first row and first symbol
    if (n == 1 && k == 1) {
        return 0;
    }
    // If k is in the first half
    if (k <= mid) {
        return kthGrammar(n - 1, k);
    } else { // If k is in the second half
        return !kthGrammar(n - 1, k - mid);
    }

       


    }