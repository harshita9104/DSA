// Given an array arr[] of integers of size N that might contain duplicates, the task is to find all possible unique subsets.

// Note: Each subset should be sorted.

// Example 1:

// Input: N = 3, arr[] = {2,1,2}
// Output:(),(1),(1 2),(1 2 2),(2),(2 2)
// Explanation: 
// All possible subsets = (),(2),(1),(1,2),(2),(2,2),(2,1),(2,1,2)
// After Sorting each subset = (),(2),(1),(1,2),(2),(2,2),(1,2),(1,2,2) 
// Unique Susbsets in Lexicographical order = (),(1),(1,2),(1,2,2),(2),(2,2)
#include<iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
    //Function to find all possible unique subsets.
   void solve(vector<int> arr, vector<int> op, int index, set<vector<int>>& s) {
    // Base case: if we have processed all elements in the array
    if (index == arr.size()) {
        // Insert the current subset into the set to ensure uniqueness
        s.insert(op);
        return;
    }

    // Recursive case 1: Exclude the current element
    solve(arr, op, index + 1, s);

    // Recursive case 2: Include the current element
    op.push_back(arr[index]);
    solve(arr, op, index + 1, s);
}

vector<vector<int>> AllSubsets(vector<int> arr, int n) {
    // Sort the input array to ensure the subsets are generated in sorted order
    sort(arr.begin(), arr.end());
    
    // This will store the current subset being generated
    vector<int> op;
    
    // Use a set to store subsets and handle duplicates automatically
    set<vector<int>> s;
    
    // Call the recursive function to generate all subsets
    solve(arr, op, 0, s);
    
    // Convert the set of unique subsets to a vector
    vector<vector<int>> ans;
    for (auto x : s) {
        ans.push_back(x);
    }
    
    return ans;
}