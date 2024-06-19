#include <iostream>
#include <cstring>
using namespace std;
void Uppercase(char word[], int n ){
  for(int i = 0; i<n ; i++){
    char ch = word[i];
    //if letter is already uppercase then continue 
    if(ch >= 'A' && ch<= 'Z'){
      continue;

    }else{
      //convert to lowercase first calculate the position of ch and then add it to A
      //mistake, this will change this char only but we have to change the letter in our char arr
      //  ch = ch - 'a'+'A'
      word[i] = ch - 'a' + 'A';


    }

  }
}
int main(){
  char word[] = "ApPlE";
  Uppercase(word, strlen(word));
  cout<<word;
  return 0;
}