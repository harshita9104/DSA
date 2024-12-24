#include <bits/stdc++.h>
using namespace std;
void permute(string s, string op){
  if(s.empty()){
    cout<<op<<" ";
    return;
  }
  //we have two choices 
  //to include the input with lower case or upper case
  string op1 = op;
  string op2 = op;
  op1.push_back(tolower(s[0]));
  op2.push_back(toupper(s[0]));
  //we have taken decision for this ip now erase it to get smaller ip
  s.erase(s.begin() + 0);
  //recursively call the permute function for smaller ip and both the outputs individually as each forms a leaf node
  //the input is updated this time and new op acc to choices will be added in op string
  permute(s,op1);
  permute(s,op2);

}

int main(){
  string s = "aB";
  string op ="";
  permute(s, op);
  return 0;
}