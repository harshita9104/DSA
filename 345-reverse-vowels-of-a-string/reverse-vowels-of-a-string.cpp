class Solution {
public:
//write a function to check if a char is vowel or not
    bool isVowel(char &ch){
        //this function takes a char as input and check if its a vowel or not
        if(ch == 'a'||ch =='e'||ch == 'i'||ch =='o'||ch == 'u'||ch =='A'||ch == 'E'||ch =='I'||ch == 'O'||ch =='U'){
            return true;
        }else{
            return false;
        }
    }
    string reverseVowels(string s) {
    
        int n = s.size();
        int i = 0; 
        int j = n-1;
        while(i<j){
            //if s[i] is not a vowel so we move ahead i++ and if s[j] is not vowel then j--
            if(!isVowel(s[i])) i++;
            if(!isVowel(s[j])) j--;
            if(isVowel(s[i]) && isVowel(s[j])){
                swap(s[i], s[j]);
                i++;j--;
            }
        }
        return s;
    }
};