class Solution {
public:
vector<string> result;

    bool isvalid(string c){
        if(c.size() > 1 && c[0] == '0') return false;

        int val = stoi(c);//this will convert this substr to val so tht we can check it
        return val <= 255;
    }
    void solve(string &s, int idx, int parts, string &curr){
        int n = s.size();
         if(idx == n && parts == 4 ){
          curr.pop_back();//last wala . hta do
          result.push_back(curr);
          return;//this is leaf node of rec tree
        }
        if(idx+1 <= n){
           string temp = curr + s.substr(idx, 1) + ".";
solve(s, idx+1, parts+1, temp);

        }
        if(idx+2 <= n && isvalid(s.substr(idx, 2))){
            string temp = curr + s.substr(idx, 2) + ".";
solve(s, idx+2, parts+1, temp);

        }
        if(idx+3 <= n && isvalid(s.substr(idx, 3))){
            string temp = curr + s.substr(idx, 3) + ".";
solve(s, idx+3, parts+1, temp);

        }
    }
    vector<string> restoreIpAddresses(string s) {
        //har ek int k baad . rakhke dekhna hoga.....
        //ab . ek int k baad bhi rakh skte , 2 int k baad bhi rakh skte, 3 k baad bhi- these are 3 possibilities, to ek recursive tree bnega or 3 alg alg input k liye 3 recursive calls honge
        //since we need to keep track of konsi position par . hai, curr string kya ban gyi hai . lagane k baad, parts- yaani . lgane k baad string k kitne parts ho gye kyuki max 4 parts hi ho skte - ye sab rec call m pass hoga
        //isvalid func bnega jo ye check krega ki substr bw two dots is valid or not acc to rules
        //2 or 3 values wali substr 0 se start nhi honi chahiye
        //value of substr <=255
        int n = s.size();
        int idx =0;
        int parts = 0;
        if (n>12){
            return {};
        }
        string curr = "";
        solve(s, 0, parts, curr);
        return result;  

    }
};