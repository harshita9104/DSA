class Solution {
public:
const int M = 1e9+7;
    long long power(long long a, long long b){
        // Modular exponentiation with modulo after every multiplication
        if(b == 0) return 1;
        long long half = power(a, b/2) % M;
        long long res = (half * half) % M;
        if(b % 2) res = (res * a) % M;
        return res;
    }
    int countGoodNumbers(long long n) {
        //formula to find
        //no of even indices in a n size arr = n+1/2
        //no of odd indices in a n size arr = n/2
        //for example n = 5 has indexes = 0,1,2,3,4
        // no of even indices are 5+1/2=3
        //no of odd indices are 5/2= 2
        // and in 0 10 9 there are 5 even number and 4 prime number
        //so for each even index possibility of a even number is 5 
        //and for each odd index possibility for odd num is 4
        // and there are n+1/2 even indices and n/2 odd indices so
        //no of good numbers are multiply the possibility at each index
        return (long long)power(5,(n+1)/2)*power(4,n/2)%M;

    }
};