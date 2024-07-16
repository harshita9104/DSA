// Given a positive integer n. Your task is to generate a string list of all n-bit binary numbers where, for any prefix of the number, there are more or an equal number of 1's than 0's. The numbers should be sorted in decreasing order of magnitude.

// Example 1:

// Input:  
// n = 2
// Output: 
// {"11", "10"}
// Explanation: Valid numbers are those where each prefix has more 1s than 0s:
// 11: all its prefixes (1 and 11) have more 1s than 0s.
// 10: all its prefixes (1 and 10) have more 1s than 0s.
// So, the output is "11, 10".
// Example 2:

// Input:  
// n = 3
// Output: 
// {"111", "110", "101"}
// Explanation: Valid numbers are those where each prefix has more 1s than 0s.
// 111: all its prefixes (1, 11, and 111) have more 1s than 0s.
// 110: all its prefixes (1, 11, and 110) have more 1s than 0s.
// 101: all its prefixes (1, 10, and 101) have more 1s than 0s.
// So, the output is "111, 110, 101".

#include<bits/stdc++.h>
using namespace std;
void solve(int one, int zero, string op,int n, vector<string> &result){
	    //BC - is when we get a n digit binary number in our op string
	    //as we are decreasing n each time we add something in op string 
	    //our base case is min valid input which is n =0
	    if(n==0){
	        result.push_back(op);
	        return;
	    }
	 //choice of including 1 is always there    
	    string op1 = op;
	    op1.push_back('1');
	    solve(one +1,zero,op1,n-1,result);
	    //2nd choice of including 0 is only valid when this condn is true
	    //hm zero tab hi use kar skte jab usse jyada 1 hm phle hi use kar chuke ho
	    if(one> zero){
	        string op2 = op; 
	        op2.push_back('0');
	        solve(one, zero+1, op2, n-1, result);
	    }
	}
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> result;
	    string op = "";
	    int one = 0;//for keeping track of no. of ones used 
	    int zero = 0;
	    solve(one, zero, op,n,  result);
	    return result;
	}