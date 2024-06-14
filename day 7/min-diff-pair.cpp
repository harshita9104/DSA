// C++ implementation of simple method to find
// minimum difference between any pair
#include <bits/stdc++.h>
using namespace std;

// Returns minimum difference between any pair
int findMinDiff(int arr[], int n)
{
	// Initialize difference as infinite
	int diff = INT_MAX;

	// Find the min diff by comparing difference
	// of all possible pairs in given array
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (abs(arr[i] - arr[j]) < diff)
				diff = abs(arr[i] - arr[j]);

	// Return min diff
	return diff;
}

// Driver code
int main()
{
	int arr[] = { 1, 5, 3, 19, 18, 25 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "Minimum difference is " << findMinDiff(arr, n);
	return 0;
}
