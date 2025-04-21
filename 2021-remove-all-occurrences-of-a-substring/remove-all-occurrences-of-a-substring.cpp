class Solution {
public:
    string removeOccurrences(string s, string part) {
        //s.find(part) will give us the first occ of this part in our string 
        //and if the left occ of this part is less than the string length(remaining) that is the last index of the string  then that part can  be removed from string s.erase(first char of that part, part.size())
        while(s.length()>0 && s.find(part) <= s.length()){
            s.erase(s.find(part), part.size());
        }
        return s;

    }
};