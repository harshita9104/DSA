// Function to find the largest number after k swaps.
// Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.


// Example 1:

// Input:
// K = 4
// str = "1234567"
// Output:
// 7654321
// Explanation:
// Three swaps can make the
// input 1234567 to 7654321, swapping 1
// with 7, 2 with 6 and finally 3 with 5

#include<bits/stdc++.h>
using namespace std;
void solve(string &str, int k, string &result, int start) {
    // Base case: if no swaps left or at the end of the string
    if(k == 0 || start == str.size() - 1) {
        return;
    }

    // Find the maximum digit from the current position to the end
    char max = *max_element(str.begin() + start, str.end());

    // Traverse from the next position to the end
    for(int i = start + 1; i < str.size(); i++) {
        // If the current digit is greater than the start digit and equal to max
        if(str[start] < str[i] && str[i] == max) {
            // Swap the digits
            swap(str[start], str[i]);

            // Update the result if the current string is greater
            if(str.compare(result) > 0) {
                result = str;
            }

            // Recursive call with one less swap and next starting position
            solve(str, k - 1, result, start + 1);

            // Backtrack by swapping back
            swap(str[start], str[i]);
        }
    }

    // Recursive call without swapping to move to the next position
    solve(str, k, result, start + 1);
}

string findMaximumNum(string str, int k) {
    string result = str;  // Initialize result with the original string
    solve(str, k, result, 0);  // Start the recursive process
    return result;  // Return the largest number formed
}
