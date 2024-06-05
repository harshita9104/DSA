//Given a sorted array arr[] of size N without duplicates, and given a value x. Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. Find the index of K(0-based indexing).

// TLE:-
// Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    //whenever sorted arr, and we have to search an elem - binary search
    int findFloor(vector<long long> v, long long n, long long x){
        int low = 0;
        int high = n-1;
        int ans = -1;
        int mid = low+ (high-low)/2;
        while(low<=high){
            if(v[mid] == x){
                //we need to give largest element smaller than or eq to x 
                //so if some element is eq to x return tht index.
                return mid;
            }else if(v[mid]<x){
                //as the arr is sorted and no duplicates either mid can be the largest elem
                //lesser than x or any elem ahead of mid index so we shrink arr [mid,high]
                low = mid;
                //suppose if K lies in bw mid and high keep your ans as mid for time being 
                //in next iteration when arr[mid,high] then mid will change again
                //and to enter this condn v[mid]<x and we are looking for largest elem <x
                //arr is sorted and it is getting shrink
                //so eventually v[mid] will point to largest elem less than x.
                ans = mid;
            }else if(v[mid]> x){
                high = mid-1;
            }
            mid = low+ (high-low)/2;
        }
        
        return ans;
        
    }

    // better - O(N)
        // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
       for(int i = n-1; i>=0; i--){
           if(v[i]<=x){
               return i;
               break;
           }
       }
       return -1;
        
    }