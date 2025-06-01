class Solution {
public:
    bool checkfreq(string s){
        int arr[26] = {0};
        for(char &ch: s){
            arr[ch-'a']++;
            // agar koi elem 2 bar aaya hai to usko aapas m swap kr skte 
            if(arr[ch-'a'] >1){
                return true;
            }
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        int n = s.size();
        //we can swap only once 
        //agar s != goal, to agar koi diff ho to bhi vo,  2 hi index par hona chahiye or 1 baar swap krke s or goal equal ho jaenge 
        //or ek baar swap karna jaruri h to agar s == goal hai to 2 cases honge agar koi 2 char be eq yani same h to 1 baar swap krne se fark nhi pdega - return true
        //lekin agar sare hi char diff h to ek baar swap nhi ho skta - return false 
    
        //first we need to find which index has diff characters 
        if(s == goal){
            return checkfreq(s);
        }
        vector<int> index;
        for(int i =0; i<n ; i++){
            if(s[i] != goal[i]){
                index.push_back(i);
            }
            //if there are more than 2 elem jo not eq hai to phir swwap karke bhi equal nhi kiya jaa skta
            //this index vector stores the index of those elem jo diff kr rhe baad m swap krne k kaam aayega
        }
        if(index.size() != 2){
                return false;
        }
        swap(s[index[0]], s[index[1]]);
        //agar 1 swap karne k baad eq ho gye then true otherwise false 
        return s == goal;
    }
};