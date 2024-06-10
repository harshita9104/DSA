//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		int firstocc(int arr[], int n, int x){
		    int low = 0; int high = n-1; int mid = low+(high-low)/2;
		    int ans = -1;
		    while(low<=high){
		        if(arr[mid]== x){
		            ans = mid;
		            high = mid-1;
		        }else if(arr[mid]<x){
		            low = mid+1;
		            
		        }else{
		            high = mid-1;
		        }
		    }
		    return ans;
		}
		int lastocc(int arr[], int n, int x){
		    int low = 0; int high = n-1; int mid = low+(high-low)/2;
		    int ans = -1;
		    while(low<=high){
		        if(arr[mid]== x){
		            ans = mid;
		            high = mid+1;
		        }else if(arr[mid]<x){
		            low = mid+1;
		            
		        }else{
		            high = mid-1;
		        }
		    }
		    return ans;
		}
	int count(int arr[], int n, int x) {
	    
	    int lastindex = lastocc(arr,n,x);
	    int firstindex = firstocc(arr,n,x);
	    if(firstindex == -1){
	        return 0;
	    }
	    
	    int count = lastindex- firstindex +1;
	    return count;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends