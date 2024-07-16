#include <iostream>
using namespace std;
//function overloading 
//here 2 functions in class have the same name but they may take diff types or number of parameters and depending upon the argument we pass while calling the function for any obj the required function will be automatically called
class print {
  public:
  void show(int x){
    cout<<"age "<<x<<endl;

  }
  void show(string str){
    cout<<"name "<<str<<endl;
  }
  //mistake ; after class definition
};
int main(){
  print obj1;
  obj1.show(20);
  obj1.show("harshita");
  return 0;

}