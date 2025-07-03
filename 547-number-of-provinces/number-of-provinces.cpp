class Solution {
public:
void bfs(int u,  unordered_map<int, vector<int>> &mp, vector<bool> &visited ){
queue<int> q;
    visited [u] = true;
    q.push(u);
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int &v: mp[curr]){
            if(!visited[v]){
                visited[v] = true;
                
                q.push(v);
            }
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
        for(int i =0; i<n ; i++){
            if(!visited[i]){
                count++;
                bfs(i, mp, visited);
                
            }
        }
        return count;
    }
};