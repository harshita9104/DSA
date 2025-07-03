class Solution {
public:
   bool dfs(int curr, unordered_map<int, vector<int>> &adj, vector<int> &color, int currColor){
    color[curr] = currColor;//har dfs call m jis node ko color karna hai (curr) or konsa color karna hai (currColor) vo pass hoga
    for(int &v :adj[curr]){
        //agar neigh same color se colored hai to false return kardo yhi p
        if(color[v] == color[curr]){
            return false;
        }
        if(color[v] == -1){
            //or colored nhi h to opp color karne k liye dfs call krdo
            int colorV = 1- currColor;
            if(dfs(v,adj, color, colorV) == false)return false;
        }
    }
    return true;
   }
   //agar mai graph k har adj node ko diff color se color kar payi it means graph bipartite h
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> adj;
      for(int i =0; i< graph.size(); i++){
        adj[i] = graph[i];
      }
     vector<int> color(graph.size(), -1);//initially all nodes are uncolored
     for(int i =0; i< graph.size(); i++){
        if(color[i] == -1){
            if(dfs(i, adj, color, 1) == false)return false;
        }
     }
     return true;

    }
};