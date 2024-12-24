//  Given an array arr containing n integers and an integer k. Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value k.

// Examples:

// Input : n = 6, arr[] = {10, 5, 2, 7, 1, 9}, k = 15
// Output : 4
// Explanation: The sub-array is {5, 2, 7, 1}.
// Input : n= 3, arr[] = {-1, 2, 3}, k = 6
// Output : 0
// Explanation: There is no such sub-array with sum 6.
// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).


 int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int j = A.size();
        int i=0;int j=0; list<int> l ; vector<int> ans;
        while(j<A.size())
        {
            while(l.size()>0&&A[j]>l.back())
            {
                l.pop_back();
            }
            l.push_back(A[j]);
            if(j-i+1<K)
            {
                j++;
            }
            else if(j-i+1==K)
            {
                ans.push_back(l.front());
                if(A[i]==l.front())
                {
                    l.pop_front();
                }
                i++;j++;
            }
        }
        return ans;
    } 