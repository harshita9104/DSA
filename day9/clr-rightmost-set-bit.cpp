//clear the rightmost set bit in a binary number
clr_bit(int n){
  n = n & n-1;
  return n;
}