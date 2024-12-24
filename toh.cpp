// The tower of Hanoi is a famous puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs n. Initially, these discs are in the rod 1. You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.

// You only need to complete the function toh() that takes following parameters: n (number of discs), from (The rod number from which we move the disc), to (The rod number to which we move the disc), aux (The rod that is used as an auxiliary rod) and prints the required moves inside function body (See the example for the format of the output) as well as return the count of total moves made.

// Note: The discs are arranged such that the top disc is numbered 1 and the bottom-most disc is numbered n. Also, all the discs have different sizes and a bigger disc cannot be put on the top of a smaller disc. Refer the provided link to get a better clarity about the puzzle.

 

 

// Examples:

// Input:
// n = 2
// Output:
// move disk 1 from rod 1 to rod 2
// move disk 2 from rod 1 to rod 3
// move disk 1 from rod 2 to rod 3
// 3
// Explanation: For N=2 , steps will be as follows in the example and total 3 steps will be taken.

#include <iostream>
using namespace std;

long long toh(int N, int from, int to, int aux) {
    // Base case: If there are no disks to move, return 0
    if (N == 0) return 0;

    // Base case: If there is only one disk, move it directly from 'from' to 'to'
    if (N == 1) {
        cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
        return 1;
    }

    // Initialize move count
    int count;

    // Step 1: Move (N-1) disks from 'from' rod to 'aux' rod using 'to' rod as auxiliary
    count = toh(N-1, from, aux, to);

    // Step 2: Move the N-th disk from 'from' rod to 'to' rod
    cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
    count += 1;

    // Step 3: Move the (N-1) disks from 'aux' rod to 'to' rod using 'from' rod as auxiliary
    count += toh(N-1, aux, to, from);

    // Return the total move count
    return count;
}
