class Solution {
public:
    string decodeAtIndex(string s, int k) {
        //while iterating on the string check if a char is a digit or not by using isdigit() function
        //agar string bnayenge to memory limit exceed hoga
        //calculate size of expanded string
        long long length =0;
        for(auto &ch: s){
           
            if(isalpha(ch)){
                length++;
            }else if(isdigit(ch)){
                int num = ch -'0';
                length = length*num;
            }
        }
        for(int i = s.size() -1; i>=0; i--){
            k = k%length;
            if(k == 0 && isalpha(s[i])){
                return string(1, s[i]);//this is the way to make a char into string 
            }
            if(isdigit(s[i])){
                length = length/(s[i] - '0');
            }else if(isalpha(s[i])){
                length--;
            }
            
        }
        return "";
    }
};