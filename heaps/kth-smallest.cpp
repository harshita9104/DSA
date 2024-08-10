// Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array. It is given that all array elements are distinct.

// Note:-  l and r denotes the starting and ending index of the array.

// Example 1:

// Input:
// n = 6
// arr[] = 7 10 4 3 20 15
// k = 3
// l=0 r=5

// Output : 
// 7

 // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> maxheap;//kth smallest find karna hai to maxheap bnega 
        //maxheap m jitne elem currently heap m hai usme se maximum elem heap k top p hota hai
        //or usse smaller elem  uske niche honge jaruri nhi vo saare sorted order m ho
        //hme heap ki size hmesha k rakhni hai usse jyada hui to top elem ko pop kardo
        //to jab arr traverse ho jaega tab heap ka top elm , kth smallest hoga kyuki usse smaller elem uske niche honge 
        for(int i = l; i<=r;i++){
            maxheap.push(arr[i]);
            if(maxheap.size() > k){
                maxheap.pop();
            }
        }
        return maxheap.top();
    }