// Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target value N.
// Find the minimum number of coins and/or notes needed to make the change for Rs N. You must return the list containing the value of coins required. 


// Example 1:

// Input: N = 43
// Output: 20 20 2 1
// Explaination: 
// Minimum number of coins and notes needed 
// to make 43. 


vector<int> minPartition(int N)
    {
      vector<int> ans;
      vector<int> coins =  { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
      for(int i = coins.size() - 1; i>=0 && N>0; i--){
          
              while(N>= coins[i]){
                  if(N/coins[i]){
                  ans.push_back(coins[i]);
                  N -= coins[i];
              }
              }
              
              
             
          
      }
      return ans;
      
    }