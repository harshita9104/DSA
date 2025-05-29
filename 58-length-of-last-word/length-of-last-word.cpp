class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count = 0;
        for(int i = n-1; i>=0; i--){
            if(s[i] == ' ' && count != 0){//if there is a space at the end of the string this will not become true coz count will be 0 
            break;

            }else if(s[i] != ' '){//if its a char then it needs to be counted 
            count++;

            }
        }
        return count;
    }
};