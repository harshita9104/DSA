// Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

// Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// Example 1:

// Input:
// [
//  [1, 0, 1],
//  [0, 1, 0],
//  [1, 0, 1]
// ]

// Output:
// 2
// Explanation:
// The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.

void dfs(int u, int vis[], vector<vector<int>> &adjlist){
              
            // ans.push_back(u);
            vis[u] = 1;
            for(auto it: adjlist[u]){
                if(!vis[it]){
                    dfs(it, vis, adjlist);
                }
                
            }
            
        }
    int numProvinces(vector<vector<int>> adj, int V) {
        int vis[V] = {0};
        int count =0;
        vector<int> adjlist[V];
        for(int i = 0;i<V; i++){
            for(int j= 0; j<V; j++){
                if(adj[i][j] == 1 && i != j){
                    //given that nodes i and j are connected if adj matrix value is 1
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                    //in undirected graph if i and j are connected then both will be in the list of neighbours of each other
                }
            }
        }
        for(int i = 1; i<V; i++){
            if(vis[i] == 0){
                count ++;
                dfs(i,vis,adjlist);
            }
            
        }
        return count;
    }