class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        int p=(1<<n);
        //Gray code for a number n is n^(n/2), and we push the same for every number in range [0, pow(2,x)).

// Explanation
// For the explanation part, we copy the MSB from binary as it is in the code and xor the remaining bits i.e. g[i] = b[i] ^ b[i-1].

// Lets take 13: 1101
// Gray code will be:
// 1 + 1^1 + 0^1 + 1^0

// If you see carefully, the xored number is actually '0110' which is equal to n/2.

        for(int i=0; i<p; i++){
            v.push_back(i^(i/2));
        }
        return v;
    }
};