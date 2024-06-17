int getbit(int n ,int i){
  return ((n &(1<<i)) ){
    return 1;
  }else{
    return 0;
  }
}
int setbit(int n , int i){
  return (n |(1<<i));
}
int clearbit(int n, int i){
  return (n & (~(1<<i)));
}