class Solution {
public:

int find(int x, vector<int> &parent){
    if(x == parent[x])return x;
    return parent[x] = find(parent[x], parent);
}
void unionset(int x, int y,vector<int> &parent, vector<int> &rank){
   int x_par = find(x, parent);
   int y_par = find(y, parent);
   if(x_par == y_par)return;

   if(rank[x_par] >rank[y_par]){
    parent[y_par] = x_par;
   }else if(rank[x_par] < rank[y_par]){
    parent[x_par] = y_par;
   }else{
    parent[x_par] = y_par;
    rank[y_par]++;
   }
}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        vector<int> rank(n , 0);
        for(int i =0; i<n ; i++){
            parent[i] = i;
        }
        //sare mails par iterate kro or ek map(string , int) jo mail ko map krega jis index ka mail hai vo uske sath
        unordered_map<string, int> mailtoind;
        for(int i = 0; i<n; i++){
            //since mail start from 1 index
            for(int j = 1; j< accounts[i].size(); j++){
                //current index wale acc ki jitni size h utna hi inner loop iterate krega 
                if(mailtoind.find(accounts[i][j]) == mailtoind.end()){
                    mailtoind[accounts[i][j]]= i;//agar already map m nahi h to mai mail k corr uske acc ka index store kr lungi

                }else{
                    //agar map m exist krti h to mujhe current index i or map m jo index h curr mail k corresponding unka union krna hoga
                    unionset(i, mailtoind[accounts[i][j]], parent, rank);
                }
            }
        }
        //agar koi 2 acc m ek mail bhi common h to unke index ka union hua yani unka par ek ho gya to ab 
        //un sare mails ko unke actual par k corresponding store krna hoga
        //ek vector lelo jha p index mails ka parent hoga
        vector<vector<string>> mergedmail(n);
        for(auto it : mailtoind){
            string mail = it.first;
            //ab iske corresponding jo index h uska par find karo
            int node = find(it.second, parent);//node m actual par store hoga aise is set m jitne mails h vo sab aajenge, or koi same mail 2 baar repeat nhi honge kyuki jab mails repeat hue the last time tab hmne un dono index ka union krke kisi ek ko par bna diya tha or map m key is mail which is unique
            //ab is par wale index corresponding mails store honge
            mergedmail[node].push_back(mail);
        }
        //abhi sirf mails hi store hue h 
        vector<vector<string>> ans;
        // merged mails jis index k corresponding stored h vo real index h yani us vector ka 0th ind will have account name 
        for(int i = 0; i<n ; i++){
            //agar koi index khali rhe gya to loop aage badhao
            if(mergedmail[i].size() == 0)continue;//par k sath merge krne k baad kuch index khali rhe jaenge
            sort(mergedmail[i].begin(), mergedmail[i].end());
            vector<string> temp;//ye ek account k name or sare mails store 
            temp.push_back(accounts[i][0]);
            for(string &mail : mergedmail[i]){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        return ans;

    }
};