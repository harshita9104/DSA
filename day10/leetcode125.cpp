//A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.


// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

bool isPalindrome(string s) {
        int n = s.size();
        //Alphanumeric characters do not include special characters
        int start = 0; int end = n-1;
        while(start<end){
          //this is also correct but will have  more time complexity
          // if (!isalnum(s[left])){
          //       left++;
          //   }else if (!isalnum(s[right])){
          //       right--;
          
            //Skip Non-Alphanumeric Characters, isalnum checks if the ch is alphanumeric or not since we need to skip the special char in our string while checking palindrome 
            //if it is special char isalnum return false , use not operator to make the condition true and to skip this special char
            if(!isalnum(s[start])){start++; continue;}
           if(!isalnum(s[end])){end--;continue;}
//Convert the characters at start and end to lowercase and compare them.

            if(tolower(s[start]) != tolower(s[end])){
                return false;
            }else{
                start++;
                end--;
            }
        }
        return true;
    }

