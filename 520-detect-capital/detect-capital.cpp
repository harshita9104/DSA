class Solution {
public:
    bool detectCapitalUse(string word) {
        //iterate thr each ch and check if they all are lying in the ascii val range of capital letters
        //capital letter range is - 65 to 90
        //lowercase letter range - 97 to 122
        // int count1 =0;
        // for(auto &ch: word){
        //    if(ch >= 65 && ch <= 90){
        //     count1++;
        //    }
        // }
        // int count2 =0;
        // for(auto &ch: word){
        //    if(ch >= 97 && ch <= 122){
        //     count2++;
        //    }
        // }
        // if(count1 == word.size() || count2 == word.size()){
            
        //     return true;
        // }
        // int count3 =1;
        // if(word[0] >= 65 && word[0] <= 90){
        //     for(int i =1; i< word.size(); i++){
        //         if(word[i] >= 97 && word[i] <= 122){
        //            count3++;
        //         }
        //     }
        // }
        // if(count3 == word.size()){
        //     return true;
        // }
        int l=word.length();

        int lower =0;
        int capital =0;
        for(int i =0; i<l; i++){
            if(islower(word[i]))lower++;
            else capital++;
        }
        //in single iteration u will get to know the number of lower and upper char 
        //1st if all are lower or upper then either lower will be eq to l or upper will be eq to l
        //2nd if only word[0] isupper then the no of lower char in it shd be length -1 
        if(lower == l || capital == l || (isupper(word[0]) && lower == l-1)){
            return true;
        }
//if the above condn doesnt fulfill tht means false
        return false;
    }
};