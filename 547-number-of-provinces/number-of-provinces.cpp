class Solution {
public:
void dfs(int u, unordered_map<int, vector<int>> &mp, vector<bool> &visited){
    visited [u] = true;
    for(int &v : mp[u]){
        if(!visited[v]){
            dfs(v, mp, visited);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
         unordered_map<int, vector<int>> mp;
        int n = isConnected.size();
        for(int i =0; i<n ; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        int count =0;
      
        vector<bool> visited(n, false);

        for(int i =0; i< n; i++){
            if(!visited[i]){
                count++;
                dfs(i, mp, visited);
            }
        }
        return count;
    }
};