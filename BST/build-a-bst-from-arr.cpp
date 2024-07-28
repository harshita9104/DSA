#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int val){
    this->data = val;
    left = right = NULL;
  }
};
Node* insert(Node* root, int val){
  //BC - jha aake val insert ho jaegi or updated root return ho jaega
  if(root == NULL){//insert jha karenge vha phele NULL hi hoga, par phele us node tak pahuchna pdega
    root = new Node(val);
    return root;//insert karke updated root return kardo
  }
  //to reach the position to insert the val
  if(val <root->data){
    //insert  function left subtree m value insert kar dega or left subtree ki updated root>left return kar dega
    root->left = insert(root->left, val);
  }
  else if(val >root->data){
    //insert  function right subtree m value insert kar dega or right subtree ki updated root->right return kar dega
    root->right = insert(root->right, val);
  }
  return root;

};
Node* buildbst(int arr[], int n){
  Node* root = NULL;
  for(int i = 0; i<n; i++){
    root = insert(root, arr[i]);
  }
  return root;
};
void inorder(Node* root){
  if(root == NULL){
    return ;
  }
  inorder(root->left);
  cout<<root->data;
  inorder(root->right);

};
int main(){
  int arr[6] = {5, 1, 3, 4, 7,2};
  Node* root = buildbst(arr,6);
  inorder(root);
  return 0;

}