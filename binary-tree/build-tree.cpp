#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int val){
    data= val;
    left = right = NULL;
  }
};
static int idx = -1;
Node* buildtree(vector<int> nodes){
  idx++;//so that everytime a node is created it takes a new value 
  if(nodes[idx] == -1){
    return NULL;
  }
  Node* currnode = new Node(nodes[idx]);//dynamically create a node and its adress is stored in currnode pointer
  currnode->left = buildtree(nodes);//since buildtree function returns node* pointer
  currnode->right = buildtree(nodes);//we assign this function node* pointer of left and right subtree

  return currnode;
}
int main(){
  vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1 ,6, -1,-1};
  Node* root = buildtree(nodes);
  cout<<root;
  return 0;
}
