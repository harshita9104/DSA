class Solution {
public:
    string makeGood(string s) {
        string result = "";
        //result string ka last char dekho agar vo aane wale char s[i] ka +- 32 hai , kyuki kisi bhi letter klowercase or uppercase ka ascii diff is 32 so to check if two adjacent letters are capital and lowercase 
        //check this condition
        for(auto &ch : s){
           if(!result.empty() && (result.back() + 32 == ch || result.back() -32 == ch)){
            result.pop_back();//if it is so then pop that letter from result string
           }else{
            result.push_back(ch);
           }
        }
        return result;
        
    }
};