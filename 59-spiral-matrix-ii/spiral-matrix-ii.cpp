
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r1 = 0, r2 = n-1;
        int c1 = 0, c2 = n-1;
        int val = 0;
// 		We have to fill the matrix layer by layer in four direction.
// From left to right ➡️:
// the row will remain constant while column is updated till reaches n-1.
// From Top to bottom ⬇️(moving down)
// The column will remain constant as n-1 and we will start filling from r1 + 1, as first row is filled in previous step & row will be updated.
// From right to left ⬅️
// we will start filling from c2 - 1 because c2 is filled in previous step.
// so the row will be fixed and c2 will be updated from c2-1 till its greater than c1.
// From botom to up ⬆️ (move up)
// the column will be fixed as c1 while row will be updated form r2 till it greater than r1.
// After that we will updates the row and column pointers, as now we will have to fill the inner layers.
// ANALYSIS -:

// TIME COMPLEXITY = O(N^2)
// SPACE COMPLEXITY = O(1)

		// result matrix
        vector<vector<int>> v(n, vector<int> (n));
        while(r1 <= r2 && c1 <= c2)
        {
            // left to right (row will be fixed)
            for(int i = c1; i <= c2; ++i)
                v[r1][i] = ++val;
				
				// move down(col will be fixed)
            for(int i = r1+1; i <= r2; ++i)
                v[i][c2] = ++val;
				
            // move right to left
            // move  up
            if(r1 < r2 && c1 < c2)
            {
                // move right to left (row will be fixed)
                for(int i = c2-1; i>c1; --i)
                    v[r2][i] = ++val;
					
					// move up (col will be fixed)
					for(int i = r2; i>r1; --i) 
                    v[i][c1] = ++val;
            }
            ++r1;
            --r2;
            ++c1;
            --c2;
        }
        return v;
    }
	// for github repository link go to my profile.
};