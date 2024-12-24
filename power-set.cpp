//same q can be asked as
//print all subsets || print all subsequences



// Given a string s of length n, find all the possible non-empty subsequences of the string s in lexicographically-sorted order.

// Example 1:

// Input : 
// s = "abc"
// Output: 
// a ab abc ac b bc c
// Explanation : 
// There are a total 7 number of subsequences possible for the given string, and they are mentioned above in lexicographically sorted order

//recursive tree - i/p o/p method

void generateSubsequences(string ip, string op, vector<string>& result) {
    // Base Case: If the input string is empty, add the output string to the result: we have reached leaf node.
    if (ip.empty()) {
        // Only add non-empty strings to the result
        if (!op.empty()) {
            result.push_back(op);
        }
        return;
    }
    //in the begining of every recursive call we need to continue
// 		    //with the old op even in smaller ip 
// 		    //there will be 2 op for each ip 
// 		    //as choices are 2 , whether to  include ip or not.
		    
    
    // Recursive Case: Create two branches, one excluding and one including the current character
    string op1 = op;     // Exclude the current character

    //for the decision to include the ip add the ip to op2 string

    string op2 = op + ip[0];  // Include the current character
    //now since we have taken decision for the 0th index elem in ip we need to erase it
    ip.erase(ip.begin());
    //now since ip has become smaller we can make recursive call for smaller ip
//and both the op1 and op2 as they form a new node with the smaller ip
    generateSubsequences(ip, op1, result);
    generateSubsequences(ip, op2, result);
}

vector<string> AllPossibleStrings(string ip) {
    vector<string> result;
    string op = "";
    generateSubsequences(ip, op, result);

    // Sort the result vector in lexicographical order
    sort(result.begin(), result.end());
    
    return result;

		}