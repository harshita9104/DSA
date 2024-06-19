#include <iostream>
#include <cstring> // Include this header for strlen

using namespace std;
bool palindrome (char word[], int n ){
  int start = 0; int end = n-1;
        while(start<= end){
            if(word[start] != word[end]){
                return false;
            }else{
                start++;
                end--;
            }

        }
        return true;
}
int main(){
  char word[] = "raciucar";
  cout<<"word is palindrome:"<<palindrome(word, strlen(word));
  return 0;
}