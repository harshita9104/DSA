#include<iostream>
using namespace std;
//operator overloading - operator ka naam same rhega but usko alg definition ya alg tareeke se use karenge

// Define a class named Complex to represent complex numbers
class Complex{
  int real; // Data member to store the real part of the complex number
  int img;  // Data member to store the imaginary part of the complex number
public:
  // Constructor to initialize the real and imaginary parts of the complex number
  Complex(int r, int i){
    real = r; // Set the real part
    img = i;  // Set the imaginary part
  }

  // Function to display the complex number in the form "real+imagi"
  void shownum(){
    cout << real << "+" << img << "i\n"; // Print the complex number
  }

  // Overload the + operator to add two complex numbers
  // This operator is a member function and takes another Complex object as an argument
  Complex operator +(Complex &c2){
    int resreal = this->real + c2.real; // Add the real parts of the two complex numbers
    int resimg = this->img + c2.img;    // Add the imaginary parts of the two complex numbers
    Complex c3(resreal, resimg); // Create a new Complex object with the result
    return c3; // Return the resulting Complex object
  }
};

int main(){
  Complex c1(2, 3); // Create a Complex object c1 with real part 2 and imaginary part 3
  Complex c2(5, 6); // Create a Complex object c2 with real part 5 and imaginary part 6
  c1.shownum();     // Display c1 (outputs "2+3i")
  c2.shownum();     // Display c2 (outputs "5+6i")
  Complex c3 = c1 + c2; // Add c1 and c2 using the overloaded + operator, store the result in c3
  c3.shownum();     // Display c3 (outputs "7+9i")

  return 0;

}
