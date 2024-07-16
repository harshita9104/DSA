; //Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in the given expression.

// ; Example: 

// ; Input: exp = “[()]{}{[()()]()}” 
// ; Output: Balanced
// ; Explanation: all the brackets are well-formed

// ; Input: exp = “[(])” 
// ; Output: Not Balanced 
// ; Explanation: 1 and 4 brackets are not balanced because 
// ; there is a closing ‘]’ before the closing ‘(‘

// ; Check for Balanced Bracket expression without  using extra stack space :


//Simulating a Stack Using the String:
// Instead of using a separate stack data structure, this code uses the input string s to store the opening brackets encountered.
// The variable top keeps track of the current "top" of the stack (initially set to -1).
// Breakdown:
// ++top: This increments the top variable before using it, effectively moving the stack pointer to the next position.
// s[++top] = ch;: After incrementing, it assigns the current character ch (which is an opening bracket) to the new top position in the string s.
// Example:
// Let's consider the string s = "{[()]}"

// Initially: top = -1
// Processing each character:
// Character {:

// top becomes 0 (++top)
// s[0] = '{'
// Character [:

// top becomes 1
// s[1] = '['
// Character (:

// top becomes 2
// s[2] = '('
// At this point, the first three characters {[( are stored in the first three positions of s, and top points to the last stored character.

// Pop Operation:
// When encountering a closing bracket, the code checks if it matches the top character in s and decrements top (simulating a stack pop operation).

// Why Use s[++top] = ch;:
// This approach avoids the need for additional space to create a separate stack, making the code slightly more space-efficient by reusing the input string. 


#include <iostream>
#include <iostream>

using namespace std;

bool areBracketsBalanced(string s) {
		int i=-1;
		for(auto& ch:s){
			if(ch=='(' || ch=='{' || ch=='[')
				s[++i]=ch;
			else{
				////Checks if i is non-negative and if the current closing bracket ch matches the last stored opening bracket s[i].
// If it matches, decrement i.
// If it doesn't match or if there are no stored opening brackets (i < 0), return false.
				if(i>=0 && ((s[i]=='(' && ch==')') || (s[i]=='{' && ch=='}') || (s[i]=='[' && ch==']')))
					i--;
				else
					return false;
			}
		}
		//Returns true if all opening brackets have been matched and i is -1, indicating a balanced string.

		if(i == -1){
            return true;

        }else{
            return false;
	}
}

int main()
{
	string expr = "{()}[]";

	// Function call
	if (areBracketsBalanced(expr))
		cout << "Balanced";
	else
		cout << "Not Balanced";
	return 0;
}

