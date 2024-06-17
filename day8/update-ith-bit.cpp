//WAF to update i th bit acc to given value(o or 1.)
#include <iostream>
using namespace std;
void updatebit(int n , int i , int k){
  //first clear ith bit
  //~(1<<i) will have 0 on only ith position and 1 at rest, iska & karenge n k sath to ith position p jo bhi h vo 0 ho jaega n k andar.
  n = n & (~(1<<i));
  //then set ith bit to k(0 0r 1)
  
  n = n| (k <<i);

}
int main(){
  updatebit(7, 2, 0);
  return 0;
}
