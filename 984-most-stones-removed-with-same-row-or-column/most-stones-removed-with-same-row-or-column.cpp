class Solution {
public:
void dfs(int u, vector<vector<int>>& stones, vector<bool> &visited){
    visited[u] = true;
    for(int i =0; i<stones.size(); i++){
        if((!visited[i] && stones[u][0] == stones[i][0])||( !visited[i] &&stones[u][1] == stones[i][1])){
            dfs(i, stones, visited);
        }
    }
}
    int removeStones(vector<vector<int>>& stones) {
        //agar kisi stone se row ya col match kr rha to unko graph k same component m daldo
        //ek connected component k sare points par jo stone h vo remove ho skte bas jo last m bachega kyuki koi or stone nhi hoga us row or col m to har connected component m last m ek stone remove nhi ho skta
        //yani jitne no of connected component hai utne stones remove nhi ho skte
        int n = stones.size();
        vector<bool> visited(n, false);
        //ek dfs call lagao ek stone par , or dfs m baad m stones vector m traverse krke same row or col wale baaki stones par bhi call lga dena same component wale stones ek dfs call m traverse ho jaenge
        int connected =0;
        //let say each stone has label same as the index number in vector stones
        for(int i =0; i< stones.size(); i++){
           
            if(!visited[i]){dfs(i, stones, visited);
             connected++;
            }
        }
        return n - connected;
    }
};