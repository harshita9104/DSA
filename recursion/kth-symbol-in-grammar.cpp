We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.

 

Example 1:

Input: n = 1, k = 1
Output: 0
Explanation: row 1: 0
Example 2:

Input: n = 2, k = 1
Output: 0
Explanation: 
row 1: 0
row 2: 01

Key Observations
the length of nth row is 2^(n-1) 
For any symbol in the first half of the n-th row, the corresponding symbol in row 

n−1 is the same.

For any symbol in the second half of the n-th row, the corresponding symbol in row  n−1 is flipped (0 becomes 1, 1 becomes 0).

        recursion m induction, base case , hypothesis
        hypothesis m smaller input k liye recursive call krte hai , 
        and we assume that we will get the answer , here the value in table for that input row and col , then we append somthing in that output of smaller input, and then get the output for original input
        now issue is how we will do smaller input here
        as we can do n-1 , but for k we need to think
        in this problem upon observation 
        we can see that the no of elem in a row is 2 ki pow n-1
        and these elem are just getting double in next row
        for nth row and the elem remains same as n-1 row till half
        then second half of nth row has the number as the complement of num on 1st half of n-1 row
        rec call for (n, k)  can be reduced to rec call for(n-1, k) if k is in 1st half 
        and if k is in second half, if k> mid
        then solve(n, k) = !solve(n-1,k-mid);

        base cond is given in q that for n =1 , k =1 the val is 0


         
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
