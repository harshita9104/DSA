//WAF to update i th bit acc to given value(o or 1.)
#include <iostream>
using namespace std;
void toggle(int n , int i){
  n = n ^ (1<<i);
  cout<<n;
}
void updatebit(int n , int i , int k){
  //first clear ith bit
  //~(1<<i) will have 0 on only ith position and 1 at rest, iska & karenge n k sath to ith position p jo bhi h vo 0 ho jaega n k andar.
  n = n & (~(1<<i));
  //then set ith bit to k(0 0r 1)
  
  n = n| (k <<i);

}
int main(){
  updatebit(7, 2, 0);
  toggle(13,2);
  return 0;
}
//alternative 
//take the bitmask (1<<i) and do xor with number.
//xor , even no. of ones = 0, odd no. of ones = 1;
// 13 ->   1101 , i = 2
// 1 <<2 = 0100
// 1101 ^ 0100 = 1001

// 13 ->   1101 , i = 1
// 1 <<1 = 0010
// 1101 ^ 0010 = 1111