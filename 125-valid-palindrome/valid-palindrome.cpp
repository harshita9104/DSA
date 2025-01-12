class Solution {
public:
 bool valid(char ch){
            if((ch >= 'a' && ch <= 'z')|| (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            return 1;    
            }
            return 0;
        };
        bool checkpalindrome(string str){
            int start =0;
        int n = str.size();
        int end = n-1;
        while(start <= end){
            if(str[start] != str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
        };
        char toLower(char c){
            if((c >= 'a' && c <= 'z') || (c >= '0' && c<= '9')){
                return c;
            }else{
                char temp = c-'A' +'a';
                return temp;
            }
        };
    bool isPalindrome(string s) {
        //sab faltu char hta do or sirf alphanumeric char ko hi tmp m push karo
        string tmp ="";
        for(int i = 0; i< s.size(); i++){
            if(valid(s[i])){
                tmp.push_back(s[i]);
            }
        }
        //ab sabko lower case m convert kardo
        //ab string tmp h to loop uski length ka chlana h
        for(int j = 0; j< tmp.length(); j++){
            tmp[j] = toLower(tmp[j]);
        }
        return checkpalindrome(tmp);
       
        
    }
};