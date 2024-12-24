// Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

// Example 1:

// Input : 
// N = 5
// A[] = {-8, 2, 3, -6, 10}
// K = 2
// Output : 
// -8 0 -6 -6
// Explanation :
// First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6

// 1. We're creating a list to store all the negative elements of a current window. At a particular point of time, the list holds negative numbers which are there in the current running window and not all the negative elements in the array. So, that we can retrieve first negative number from the current window.
// 2. When we reached the window size, we need to perform two operations:-
// -> First, we have to retrieve the answer that is the first negative number from the current window. We're checking if the list is empty or not. If it is empty, then there is no negative number in the current window. In that case we'll push 0 in the vector.
// If it's not empty, then the first element in the list is the first negative number of the current window., pushing that into the vector.
// -> Second, we need to slide the window. For that we need to remove the first element of the current window, and add the next element from the array to the window. But before removing the first element, we need to check whether it belongs to the list or not. If it belongs to the list, we need to remove it from the list, as it will not be a part of our next window. So, if the first element is found to be a negative number, then we have to remove it from the list, and this number is happened to be the front element of the list. Then, incrementing the values of i and j to slide the window.

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    vector<long long> ans;
    deque<long long> neg;//using it becoz we need only insert and erase operation in O(1)
    int start = 0;
    int end = 0;
    while(end<N){
        if(A[end] <0){//if the elem is neg push it in deque
           neg.push_back(A[end]); //FIFO to 1st neg number ko front se access kr paenge
        }
        if(end-start+1 <K){
            end++;//jab tak window ki size k nhi ho jaati end ko inc karte raho
        }else if(end-start+1 == K){//yani window size k ho gyi h
        //edge case deque empty h yani koi neg number nhi h hmari current window m tab vector m 0 push kardo
            if(neg.size() == 0){
                ans.push_back(0);
            }else{
                //agar deque empty nhi h to uske front p current window ka 1st neg number h
                ans.push_back(neg.front());
                if(A[start] == neg.front()){
                    //kyuki window slide kr rhe to start ko window se htana hoga to usko list se bhi hatao
                    neg.pop_front();//calculation sirf deque p karni h
                }
                //window slide krdo
                start++;
                end++;
                
            }
            
        }
        
        
    }
    return ans;
 }