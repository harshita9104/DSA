// Given weights and values of n items, we need to put these items in a knapsack of capacity w to get the maximum total value in the knapsack. Return a double value representing the maximum value in knapsack.
// Input: n = 3, w = 50, value[] = [60,100,120], weight[] = [10,20,30]
// Output: 240.000000
// Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 
 static bool compare(pair<double, int> p1, pair<double, int> p2){
      //to sort the ratio on basis of 1st para price and in desc order
     return p1.first > p2.first;
  }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
       vector<pair<double,int>> ratio(n ,make_pair(0.0,0));//we need to make a vector of ratios which will have pair of(price,index) to keep track of index of a price and initialise an empty pair in beginning
      vector<double> r(n);
       for(int i = 0; i<n ; i++){
           r[i] = arr[i].value/(double)arr[i].weight;//price nikal lo price/kg for every item
           ratio[i] = make_pair(r[i], i);//pair banalo price or corresponding index ka 
       }
       sort(ratio.begin(), ratio.end(), compare);//now ratio is sorted in desc order
    //   sabse jyada price wala item sabse phle h ratio m, vo sabse phle bag m jaega
    double ans = 0.0;
    for(int i = 0; i<n ; i++){
        //access the index of ratio to get the corresponding weight and val of item
        int idx = ratio[i].second;
        if(arr[idx].weight <= w ){
            //complete item daaldo bag m
            ans += arr[idx].value;
            w -= arr[idx].weight;
        }else{
            //partially daalo item ko
            ans += ratio[i].first* w;//price of item * remaining cap of bag
            break;//since saari rem cap m item bhar diya h no rem space i bag, break from loop
            
        }
    }
    return ans;
    }