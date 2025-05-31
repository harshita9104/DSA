class Solution {
public:
    bool isPalindrome(string s){
        string s2=s;
        reverse(s2.begin(),s2.end());
        return s==s2;
    }
    void getParts(string s, vector<string>& partitions, vector<vector<string>>& ans){
        if(s.size()==0){
            ans.push_back(partitions);
            return;
        }
        for(int i=0;i<s.size();i++){
            string part = s.substr(0,i+1);

            if(isPalindrome(part)){ //if left part is palindrome then move further
                partitions.push_back(part);
                getParts(s.substr(i+1),partitions,ans);
                partitions.pop_back(); //backtracking
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        getParts(s,partitions,ans);
        return ans;
    }
};