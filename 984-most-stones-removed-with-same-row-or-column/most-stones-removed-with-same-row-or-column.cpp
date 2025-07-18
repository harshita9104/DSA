class Solution {
public:
   void dfs(int u, vector<bool> &vis, vector<vector<int>>& stones){
    vis[u] = true;
    //u is the representing a stone u is the index of a stone in stones vector
    int x = stones[u][0];
    int y = stones[u][1];
    for(int i = 0; i<stones.size(); i++){
        if((!vis[i] && stones[i][0] == x )|| (!vis[i] && stones[i][1] == y)){
            dfs(i, vis, stones);
        }
    }
   }
    int removeStones(vector<vector<int>>& stones) {
        //isme no of connected components  = jitne stones remove nhi ho skte 
        //kyuki jo same  connected component m h yani jinka row ya col same h unko hm hta denge last m
        //us component ka ek stone bachega jisko nhi hta skte
        // simple no of strongly connected comp nikalke dfs se traverse krke
        // usko n se subtract krdo
        int n = stones.size();
        vector<bool> vis(n, false);
        int comp =0;
        //jitne coordinates given h utne stones h kyuki ek cord pr ek stone h
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, stones);
                comp++;
            }
        }
        return n-comp;
    }
};