#include <iostream>
#include <cstring> // Include this header for strlen

using namespace std;
void reverse(char word[],int n){
  int start = 0; int end = n-1;
  while(start<end){
    swap(word[start], word[end]);
    start++;
    end--;
  }

}
int main (){
  //declare a char arr word and take string lateral as input
  char word[] = "hello";
  //call function reverse
  reverse(word, strlen(word));
  cout<<"reverse- "<<word<<endl;
  return 0;
}