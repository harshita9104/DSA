//You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.
//Iterating Over the String: The loop iterates over each character of the input string str.
// Replacing Spaces: When a space character is found (str[i] == ' '), @40 is appended to the result string.
// Appending Non-Space Characters: If the character is not a space, it is appended to the result string as it is.
// Returning the Result: The modified string is returned.


#include <bits/stdc++.h> 
#include <string>
string replaceSpaces(string &str){
	string result;
	for(int i = 0; i< str.size(); i++){
		if(str[i] == ' '){
			result += "@40";
		}else{
			result += str[i];

		}
		
}
return result;
	}