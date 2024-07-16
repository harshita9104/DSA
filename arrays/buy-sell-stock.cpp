//q - u are given prices of stock of each day 
//you can buy a stock and then sell it on later days 
//find the max profit u can obtain buy and selling stock
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void maxprofit(int prices[], int n){
  //in case profit h hi nhi to 0 return karna h given in q 
  int maxprofit = 0;
  //declare an arr whose size is the max length of price arr
  //minbuy arr will contain the min buy price for each selling day
  int minbuy[100000];
  //kyuki 0th day se phle koi din hi nhi h buy karne k liye iska minbuy INT_MAX kardo , itna jyada ki buy hi nhi kr skte
  minbuy[0] = INT_MAX;
  for(int i = 1; i<n; i++){
    //minbuy[i-1] is already containing the min of the previous values and usko prices[i-1] se compare kardo or unka min jo hoga vo ith day ka minbuy price hoga
    minbuy[i] = min(minbuy[i-1], prices[i-1]);


  }
  int currprofit = 0;
  //kyuki har din sell day or har din ka minbuy price nikal hi liya h to har din ka profit bhi nikal lo
  for(int i =0; i<n; i++){
    currprofit = prices[i] - minbuy[i];
    maxprofit = max(maxprofit, currprofit);
  }
  cout<<maxprofit<<endl;

}
int main(){
  int prices[] ={ 2,4,3,6,8,5,9};
  int n = sizeof(prices)/sizeof(int);
  maxprofit(prices, n);
  return 0;
}