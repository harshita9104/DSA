#include <bits/stdc++.h>
using namespace std;
void deleteBottom(stack<int> &st){
  stack<int> aux;
  while(st.size() >1){
    aux.push(st.top());
    st.pop();
  }
  st.pop();
  while(!aux.empty()){
    st.push(aux.top());
    aux.pop();
  }
}
//optimal approach
//recursive solution
void removebottomelem(stack<int> &st){
  //base case
  if(st.size() ==1 ){
    st.pop();//remove the bottom elem from stack
    return;
  }
  int topelem = st.top();//store the top elem to push it back later
  st.pop();//remove the top elem
  //recursively call to reach the bottom elm
  removebottomelem(st);

  st.push(topelem);//rebuild the stack without bottom elm
}