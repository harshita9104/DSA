class Solution {
public:
//tle na maare isliye memoize   krlo agar koi string k liye phle se check kr rakha hai ki concatenate kr skte ky to uskeliye phirse check krna nhi pdega
unordered_map<string,bool> mp;
    bool isConcatenated(string word,unordered_set<string> &st){
        int l = word.size();
        if(mp.find(word) != mp.end()){//agar map m hai vo word yani uske liye phle concatenation check kiya h
            return mp[word];//us word k corresponding jo bhi stored result h vo yhi se return krdo
        }
        for(int i = 0; i<l ; i++){
            //calculate prefix substr we are at currently at ith index starting from 0 so the prefix will be starting from 0 and length i+1
            //and suffix will be starting from i+1 index and u dont specify length it will assume the end of string 
            string prefix = word.substr(0,i+1);
            string suffix = word.substr(i+1);//if u dont specify it will take the rem substr starting from i+1
            //in this q we need to break a word into parts and check if those parts are present in our set or not
            //so there can be only 2 conditions
            //the substr till ith index is present in set and the rem suffix is also present in set then  this word will return true
            //and since our prefix is already being checked from scratch tht it is present in set 
            //we will again conctenate suffix and check if further parts of suffix are present in set or not
            if((st.find(prefix) != st.end() && st.find(suffix) != st.end()) || (st.find(prefix) != st.end() && isConcatenated(suffix, st))){
                return mp[word] = true;
            }

        }
        return mp[word] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        //first create a set which will store all the unique words of given vector and we can find or look for a word easily in set when we will break the word and look if it is present in given set of words or not
        mp.clear();
        unordered_set<string> st(begin(words), end(words));
        vector<string> result;
        for(int i =0; i<n ; i++){
            string word = words[i];
            if(isConcatenated(word,st)){
                result.push_back(word);
            }
        }
    return result;
    }
};