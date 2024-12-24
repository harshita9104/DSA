// You are given a positive integer ‘n’.
// Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).
#include <iostream>
using namespace std;

    long long int sqrtInteger(int n){
        int s = 0;
        int e = n;// sqrt of 1 is 1 
        long long int  mid = s+ (e-s)/2;
        int ans = -1;
        
        while(s<=e){
            long long int sq = mid*mid;
            if(sq == n){
               
               return mid;//return immediately when sqrt is found
            

            }else if( sq< n){
                ans = mid;

                s = mid +1;
            }else{
                e = mid -1;
            }
            mid = s+ (e-s)/2;
        }
        return ans;
    }
    double morePrecision(int n, int precision, int tempSol){
      double factor =1;
      double ans = tempSol;
      //1st add 0.1 and then take the square of (tempSol.1) if it is (tempSol.1)^2 < n then store the value in ans and then again add 0.1 and again take its sq and compare with n ,the moment it exceeds stop! 
      //come out of inner loop iterate for the 2nd time but this time the factor becomes 0.01 and it gets added to the last stored val of ans the outer loop runs 3 times as we want upto 3 decimal places.
      for(int i =0; i<precision; i++){
        factor = factor/10;
        for(double j = ans ; j*j < n; j += factor){
          ans = j;
        }
      }
      return ans;
    }
    int main(){
      int n; 
      cout<<"enter the number"<<endl;
      cin>>n;
      int tempSol = sqrtInteger(n);
      cout<< "exact val upto 3 decimal places"<< morePrecision(n,3,tempSol)<<endl;
      return 0;

      
    }