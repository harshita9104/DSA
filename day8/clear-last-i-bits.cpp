#include <iostream>
using namespace std;
void clear_ibit(int n , int i ){
  n = n &((~0)<<i);
  cout<<n;

}
int main(){
  clear_ibit(7, 2);
  return 0;
}