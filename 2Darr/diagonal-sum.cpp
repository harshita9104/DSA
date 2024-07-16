// Given a square matrix mat, return the sum of the matrix diagonals.

// Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

 

// Example 1:


// Input: mat = [[1,2,3],
//               [4,5,6],
//               [7,8,9]]
// Output: 25
// Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
// Notice that element mat[1][1] = 5 is counted only once.

#include<bits/stdc++.h>
int diagonalSum(vector<vector<int>>& mat) {
        //for primary diagonal i =j
        // for sec diag j = n-i-1
        //no need of nested loop since j can be written in terms of n and i
        //since in odd matrix one common elem will appear in both the diag as both tha bove cond are true for it so consider it only once in sum
        int sum =0;
        int n = mat.size();
        for(int i = 0; i< mat.size(); i++){
            sum += mat[i][i];
            //since i = n-i-1 for common elem so to avoid it
            if(i != n-i-1 ){
                sum += mat[i][n-i-1];
            }

        }
        return sum;
    }