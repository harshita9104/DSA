//Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

//brute force 
int lenOfLongSubarr(int A[],  int N, int K) 
    { 
       int maxlength = 0;
       for(int i = 0; i<N; i++){
           int sum = 0;
          
           for (int j = i; j<N; j++){
               sum += A[j];
               if(sum == K ){
                   maxlength = max(maxlength, (j-i +1));
                   
               }
               
           }
       }
       return maxlength;
    } 
    
//better - use hashmap, 
//time complexity- O(nlogn), for ordered map, O(n*1) for unordered map if no collisions.
//optimal solution if arr has  0 and neg 
  int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        //suppose if input is [2,0, 0, 3] and k = 3 so the longest subarr length should be 3
        // but the code will give 1 as till index 2 the rem sum is 2 
    
      
      //better - using hashmaps
      //declare a hashmap whose 1st parameter is ths sum till index i and second para is i.
      map<long long , int> summap;
      //initialise sum and maxlength of subarr
      long long  sum = 0;
      int maxlength = 0;
      //iterate through arr A and if the sum sum upto i is == k then put the length of that subarr
      //from 0 to i index which is i+1 in maxlength.
      for(int i = 0 ; i<N; i++){
          sum += A[i];
          if(sum == K ){
              maxlength = max(maxlength, i+1);
          }
          //but suppose the sum till i index is x and somewhere earlier it was x-k 
          //which can be found out by searching for the rem x-k , x is current sum in hashmap
          //there must be a subarr in the middle with sum k so
          long long rem = sum - K;
          //this means whether rem is present in hashmap
          if(summap.find(rem ) != summap.end()){
              //the length of this subarr would be (current index - index of rem )
              int length = i - summap[rem];
              maxlength = max(maxlength, length);
              
              
          }
          //imp condition to when arr contains 0 and neg.
          //creating hashmap upon calculating sum after each iteration.
         //but reupdate the index in hashmap only for the sum that does not exist previously 
         //as we need to find the longest subarr
         if(summap.find(sum) == summap.end()){
             summap[sum] = i;
         }

          
      }
      return maxlength;
      
    } 
    //optimal - 2 pointer and greedy app
    //approach in which we trim down the arr by moving left pointer as the sum gets greater than K.
    //only for positive elemnets
    //TC is O(2n) as the inner loop would run approx total n times in entire iteration.
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
       int left = 0;
       int right = 0;
       int sum = A[0];
       int maxlength = 0;
       
       while(right<N){
           //but should we do this always as the sum is increasing but we want the sum to be K .
           right++;
           if(right<N){
               sum +=A[right];
           }
           //so we trim down the arr by moving left pointer as the sum gets greater than K.
           //and we will keep moving the left pointer till the sum >K 
           //and the left pointer should be less than right pointer,otherwise a subarr wont exist.
           while(sum>K && left<= right){
               sum -= A[left];
               left++;
           }
           if(sum == K){
               maxlength = max(maxlength, right-left+1);
               
               
           }
       }
       return maxlength;
    } 

    //for neg elements
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        unordered_map<int,int>mp;
        int sum=0;
        mp[0] =-1;
        int maxi = 0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(mp.find(sum-k) != mp.end()){
                maxi = max(maxi,i-mp[sum-k]);
            }
            if(mp.find(sum)==mp.end())
                mp[sum] =i;
            
        }
        return maxi;
    }
