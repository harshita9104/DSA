class Solution {
public:
    string multiply(string s1, string s2) {
        if (s1 == "0" || s2 == "0") return "0";
        string s1n ="";
        string s2n ="";
//The base case handling (if any of string is zero, simply return zero)
// Check whether string are negative or not, store the first characters if negative (firstChar = '-')
// If both negative, initialize both the string as empty string. Beacause we need to return our result as a string, so to store the sign if any of the string is negative the answer should carry the sign '-' at beginning.

        if(s1[0] == '-'){
            s1n ="-"; s1 = s1.substr(1);
        }
        if(s2[0] == '-'){
            s2n = "-"; s2 = s2.substr(1);
        }

        // if both negative just empty the string
        if(s2n == "-" && s1n == "-") s1n=s2n="";
        
        int n = s1.size();
        int m = s2.size();
        string res(n+m,'0');
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){                
                int num = (s1[i]-'0') * (s2[j]-'0') + (res[i+j+1]-'0'); // res will store carry
                res[i+j+1] = num % 10 + '0';
                res[i+j] += num / 10; // carry
                
            }
        }
        
        int i=0;
        while(i < res.size() && res[i] == '0') i++;
        return s1n + s2n + res.substr(i);
    }
};