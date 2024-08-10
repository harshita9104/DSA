// Given an array arr of n positive integers and an integer k, Your task is to return k largest elements in decreasing order. 

// using meanhaep
vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	     vector<int>ans;
        
       priority_queue<int, vector<int>,greater<int>> minheap;
        for( int i =0 ;i<n;i++ )
        {
            
            minheap.push(arr[i]);
            if(minheap.size() > k){
                minheap.pop();
            }
            

        }
        
        while( !minheap.empty())
        {
            
           ans.push_back( minheap.top());
           minheap.pop();
           
           
        }
        reverse(ans.begin(), ans.end());
        return ans;
        


	}

  //using maxheap
  //User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	     vector<int>ans;
        
       priority_queue<int>q;
        for( int i =0 ;i<n;i++ )
        {
            
            q.push(arr[i]);
            

        }
        
        while( k!=0)
        {
            
           ans.push_back( q.top());
           q.pop();
           k--;
           
        }
        return ans;
        


	}

};