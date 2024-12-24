class Solution {
public:
    string reverseWords(string s) {
        vector<string> tmp;
        //initialise empty string with no space , this is used to build  a word as we iterate thr the string
        string str = "";
        for(int i = 0; i< s.size(); i++){
          //if we encounter a space i.e; a word is over and str now stores the word push this word in temp and empty the string so that it can store new word
            if(s[i] == ' '){
                tmp.push_back(str);
                //mistake
                str = "";
            }else{
                str += s[i];
            }
        }
        //kyuki last word k baad space nhi h loop khatam hone k baad usko alg se tmp m push kro

        tmp.push_back(str);
        string ans= "";
        //iterate through tmp from back and put the words in ans string
        for (int i = tmp.size() - 1; i > 0; --i) {
           if(tmp[i] == " "){
            continue;
           } 
           else if(tmp[i] != " "){
			   ans += tmp[i] ;
               ans+= ' ';

		   } 

        }
        //this is to avoid the addition of space after adding last word in ans string
        ans+= tmp[0];

        return ans;

    }
};
// above code doesn’t handle the cases when the string starts with space. 
//


//solution using stack