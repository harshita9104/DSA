//Given a string S. The task is to print all unique permutations of the given string that may contain dulplicates in lexicographically sorted order. 

// Example 1:

// Input: ABC
// Output:
// ABC ACB BAC BCA CAB CBA
// Explanation:
// Given string ABC has permutations in 6 
// forms as ABC, ACB, BAC, BCA, CAB and CBA 

//check copy for explaination -aditya verma backtracking

//RECURSIVE SOLUTION

#include<bits/stdc++.h>
using namespace std;
void solve(string S, string op, vector<string> &result){
		    if(S.size() == 0){
		        result.push_back(op);
		        return;
		    }
		    unordered_set<char> set;
		    for(int i =0; i<S.size(); i++){
		        if(set.find(S[i]) == set.end()){
		            set.insert(S[i]);
		            string newS = S.substr(0,i) +S.substr(i+1);
		            string newop = op+ S[i];
		            solve(newS, newop, result);
		            
		        }
		    }
		}
		vector<string> find_permutation(string S)
		{
		    string op ="";
		    vector<string> result;
		    solve(S,op, result);
		    return result;
		}
    
    //BACKTRACKING SOLUTION

    void solve(string S, int start, vector<string> &result){
		    if(start == S.size() -1){
		        result.push_back(S);
		        return;
		    }
		    //mistake -declare the set outside the loop
		     unordered_set<char> set;
		    for(int i =start; i< S.size()  ; i++){
		       
		        if(set.find(S[i]) == set.end()){
		            set.insert(S[i]);
		            swap(S[start] , S[i]);
		            solve(S, start+1,result);
		            swap(S[start] , S[i]);
		        }
		    }
		    
		    
		}
		vector<string>find_permutation(string S)
		{
		    int start = 0;
		    vector<string> result;
		    solve(S,start, result);
		    return result;
		}