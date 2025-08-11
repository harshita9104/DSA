#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        //To find the number of 1s in the binary representation of numbers from 0 to ( n ), we can use a pattern:

// If ( i ) is even, the number of 1s in ( i ) is the same as the number of 1s in ( i/2 ) (right-shifting an even number halves it without adding a new 1).
// If ( i ) is odd, the number of 1s in ( i ) is the number of 1s in ( i - 1 ) plus one additional 1 (as adding 1 to an even number makes it odd).
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};