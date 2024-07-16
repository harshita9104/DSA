//parent and child class contain same function with diff implementation  but at the run time when obj of child class is created then function of child  class is called and function of parent class is overridden
#include<iostream>
using namespace std;
class parent{
  public:
  void show(){
    cout<<"parent class"<<endl;
  }
};
class child: public parent{
  public:
  void show(){
    cout<<"child class"<<endl;
  }
};
int main(){
  child obj1;
  obj1.show();
  return 0;
}
