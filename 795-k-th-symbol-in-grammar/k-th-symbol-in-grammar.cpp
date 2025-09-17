class Solution {
public:
    int kthGrammar(int n, int k) {
        //recursion m induction, base case , hypothesis
        //hypothesis m smaller input k liye recursive call krte hai , 
        //and we assume that we will get the answer , here the value in table for that input row and col , then we append somthing in that output of smaller input, and then get the output for original input
        //now issue is how we will do smaller input here
        //as we can do n-1 , but for k we need to think
        //in this problem upon observation 
        //we can see that the no of elem in a row is 2 ki pow n-1
        //and these elem are just getting double in next row
        //for nth row and the elem remains same as n-1 row till half
        //then second half of nth row has the number as the complement of num on 1st half of n-1 row
        //rec call for (n, k)  can be reduced to rec call for(n-1, k) if k is in 1st half 
        //and if k is in second half, if k> mid
        //then solve(n, k) = !solve(n-1,k-mid);

        //base cond is given in q that for n =1 , k =1 the val is 0
        if(n == 1 && k == 1)return 0;
        int mid = pow(2, n-1)/2;
        if(k<= mid)return kthGrammar(n-1, k);
        else 
         return  (!kthGrammar(n-1, k-mid));
        
        

    }
};