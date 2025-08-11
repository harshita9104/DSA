    class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long n = rowIndex + 1;
        //Start with the first value 1 at index 0.

// Use symmetry: if you calculate the i-th element from the left, you automatically know the i-th from the right.

// Use multiplication & division to build each next value without recomputing factorials.

// Avoid floating point errors by using long long.

        vector<int> arr(n, 0);
        arr[0] = 1; 
        if(rowIndex ==0) return arr;
        arr[n-1]=1;
        if(rowIndex == 1) return arr;
        
        long long mul = n - 1;
        long long i=1, j=n-2;
        while(i<=j)
        {
            arr[i] = arr[i-1] * mul / i;
            arr[j] = arr[i-1] * mul / i;
            mul--;
            i++;
            j--;
        }
        return arr;
    }
};