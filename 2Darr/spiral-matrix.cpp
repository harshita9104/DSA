// Given an m x n matrix, return all elements of the matrix in spiral order.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

#include<bits/stdc++.h>
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int srow = 0;
        int scol = 0;
        int erow = m-1;
        int ecol = n-1;
        vector<int> ans;
        while(scol<= ecol && srow <= erow){
            //i - iterator thr rows
            //j is the iteratir thr col
            //iterating thr top boundary where srow is fixed and we iterate thr col starting from scol to ecol
            for(int j = scol; j <= ecol; j++){
                ans.push_back(matrix[srow][j]);
            }
            //iterating thr right boundary where ecol is same and we iterate thr rows starting from srow+1 till erow
            for(int i = srow +1 ; i <= erow; i++){
                ans.push_back(matrix[i][ecol]);
            }
            //iterating thr bottom where erow is same and we iterate reverse thr col starting from ecol-1 till scol
             for(int j = ecol-1 ; j >= scol ; j--){
                // /this is for the odd row matrix where in the end when srow = erow there is only one middle row left no loop so once we traversed top boundary no need to traverse again as we will get duplicate in tht case
                if(srow == erow){
                    break;
                }
                ans.push_back(matrix[erow][j]);
            }
            //iterating thr left where scol is same and we iterate from erow-1 to srow +1
            for(int i = erow-1  ; i >= srow+1 ; i--){
                if(scol == ecol){
                    break;
                }
                ans.push_back(matrix[i][scol]);
            }
            //before starting next loop iteration modify the value since we have traversed srow, scol, erow, ecol 
            srow++;
            erow--;
            scol++;
            ecol--;
        }
        return ans;
    }


