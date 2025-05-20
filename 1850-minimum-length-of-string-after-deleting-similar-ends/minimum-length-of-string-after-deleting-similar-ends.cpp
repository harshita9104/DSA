class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int l = 0;
        int h = n-1;
        string prefix = "";
        string suffix = "";
       
        while(l<h){
            if(s[l] == s[h]){
                prefix += s[l];l++;
                while(l <= h &&  s[l] == s[l-1]){
                   prefix += s[l];
                   l++;
                }
                suffix  += s[h];h--;
                while(h>= l && s[h] == s[h+1]){
                   suffix += s[h];
                   h--;
                }

            }else{
                break;
            }
        }
         return max(0, h - l + 1);
        
    }
};