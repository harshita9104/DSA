//Swap given two numbers and print them. (Try to do it without a temporary variable.) and return it.

class Solution{   
public:
    pair<int, int> get(int a, int b){
     
     a = a^b;
     b = a^b;//(a^b)^b = a
     //
     //now since b = a
     a = a^b;//(a^b)^a = b
     return{a,b};
     
    }
};