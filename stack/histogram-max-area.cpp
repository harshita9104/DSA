// Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

// Example 1:

// Input:
// N = 7
// arr[] = {6,2,5,4,5,1,6}
// Output: 12
// Explanation: In this example the largest area would be 12 of height 4 and width 3. We can achieve this 
// area by choosing 3rd, 4th and 5th bars.

// Input: heights = [2,1,5,6,2,3]
// Output: 10
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//observations : a building of a height can be expanded as rectangle in a direction until it finds a building of smaller height 
//so the moment we get the nearest smaller to right or left we stop width expansion of our rectangle
//now how to find the width of this rectangle formed
//first for a particular index find the NSR & NSL the width expansion of rectangle for that height will be NSR index - NSL index -1 ,

 void nsr(vector<int>& heights, int n, vector<int>& v1){
    
  stack<pair<int, int>> s;
for(int i = n-1 ; i>= 0; i--){
    if(s.size() == 0){
        //if no nsr elem exist then in right side n index is the nsr assume 0 height building there
      v1.push_back(n);
    }else if(s.size() >0 && s.top().first < heights[i] ){
            v1.push_back(s.top().second);
        }else if(s.size() >0 && s.top().first >= heights[i]){
            while(s.size() >0 && s.top().first >= heights[i]){
                s.pop();
            }
            if(s.size() == 0){
                v1.push_back(n);

            }else{
                v1.push_back(s.top().second);
            }
        }
        s.push({heights[i], i});
  }
        
        reverse(v1.begin(),v1.end());
        

};
void nsl(vector<int>& heights, int n, vector<int>& v2){
    
  stack<pair<int, int>> s;
  //observations
  //standing at an index if we look in left to count the elem who are smaller or eq to current index elem
  //then we stop our serach at next greater to left elem
  //second observation is the count of smaller or eq to elem in left is equal to current index - index of its NGL elem
  // so we store in stack NGL along with the  the index of elem
  //and for each index we store the index of its corresponding NGL elem in vector v
  // so that we can obtain stock span for each index by doing i - v[i]
  for(int i = 0; i<n ; i++){
    if(s.size() == 0){
        //if no nsl elem exist then in left -1 index is the nsl assume 0 height building there
      v2.push_back(-1);
    }else if(s.size() >0 && s.top().first < heights[i] ){
            v2.push_back(s.top().second);
        }else if(s.size() >0 && s.top().first >= heights[i]){
            while(s.size() >0 && s.top().first >= heights[i]){
                s.pop();
            }
            if(s.size() == 0){
                v2.push_back(-1);

            }else{
                v2.push_back(s.top().second);
            }
        }
        s.push({heights[i], i});
  }
       


};
   
void largestRectangleArea(vector<int>& heights, int n) {
       
        int width[n];
vector<int> v1;
vector<int> v2; 
nsr(heights, n , v1);
nsl(heights, n, v2);
        for(int i = 0; i <n; i++){
           width[i] =  v1[i] - v2[i] -1;
        }
        int area[n];
        int maxarea = 0;
        for(int i = 0 ; i<n ; i++){
            area[i] = width[i] *heights[i];
            maxarea = max(maxarea, area[i]);
        }
        cout<< maxarea;

    }
int main(){
  int n;
  cin>>n;
  vector<int> heights(n);
  for(int i = 0; i<n; i++){
    cin>> heights[i];
  }
 largestRectangleArea(heights,n);
  return 0;
}