class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int i=0,j=0;
        list<int> l;
        int n = arr.size();
        vector <int> ans;
        
       	while (j < n)
	{
		  while(l.back()<arr[j] && l.size()>0){//calculation to remove smaller elements which are coming before j
		      l.pop_back();
		  }
		  
		  l.push_back(arr[j]);
		  
		if (j - i + 1 < k)
		{ //moving pointer j to window size k
			j++;
		}
		else if (j - i + 1 == k)
		{
		  ans.push_back(l.front());//as front element will be largest
		  
		  if(l.front()==arr[i]) l.pop_front();//removing 1st element before sliding window
			
			i++;				//moving both pointers forward

                j++;
            }
        }

        return ans;
    }
};
