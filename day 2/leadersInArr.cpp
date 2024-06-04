//Given an array A of positive integers. Your task is to find the leaders in the array. An element of the array is a leader if it is greater than all the elements to its right side or if it is equal to the maximum element on its right side. The rightmost element is always a leader. 

// Example 1:

// Input:
// n = 6
// A[] = {16,17,4,3,5,2}
// Output: 17 5 2
// Explanation: The first leader is 17 
// as it is greater than all the elements
// to its right.  Similarly, the next 
// leader is 5. The right most element 
// is always a leader so it is also 
// included.


//brute
vector<int> leaders(int a[], int n){
        vector<int> ans;
        for(int i = 0;i<n; i++){
            bool leader = true;
            for(int j= i+1; j<n; j++){
                if(a[j]>  a[i]){
                    leader = false;
                }
            }if(leader == true){
                ans.push_back(a[i]);
            }
        }
        return ans;
        
    }
    //optimal
     vector<int> leaders(int a[], int n){
        vector<int> ans;
        int maxi = a[n-1];
        for(int i = n-1; i>=0; i--){
            maxi = max(maxi, a[i]);
            if(a[i]>=maxi){
                ans.push_back(a[i]);
                //  sort(ans.begin(), ans.end());
                reverse(ans.begin(), ans.end());
            }
        }
        return ans;
     }