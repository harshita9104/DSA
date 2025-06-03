class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string result = "";
        for(int i =0; i< s.size() ; i++){
            if(isalpha(s[i])){
               result += s[i];
            }
            else {
                if(result.size() != 0){
                  result.pop_back();
                }
                
            }
        }
        string ans = "";
        for(int i =0; i< t.size() ; i++){
            if(isalpha(t[i])){
               ans += t[i];
            }else{
                if(ans.size() != 0){
                   ans.pop_back();
                }
                
            }
        }
      return result == ans;  
    }
};