class Solution {
public:
//if n is even then it's power can be written as = 2*n/2 so take square of the number x and keep the power as n/2 
//when x is odd take one x out and then it will be even callsolve for n-1 value
   double solve(double x, long n){
    if(n == 0)return 1;
    if(n<0) return solve(1/x, -n);
    if(n %2 == 0)return solve(x*x, n/2);
    return x*solve(x*x, n/2);
   }
   //we converted n to long becoz it is not possible to represent INT_MAX value in int type 
    double myPow(double x, int n) {
        return solve(x, long(n));
    }
};