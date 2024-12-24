// You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
// Note: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.

// Function to return a list containing the DFS traversal of the graph.

//jis bhi vertex p jaao , uski 1st unvisited node visit krni hai or agar koi aisa node mil gya jiske saare neighbours visit ho gye hai to backtrack karke piche wale nodes k liye check krna hai kahi unke to koi unvisited neigh nhi h , recursion will be used u will be current node or uske 1st unvisited neigh ko visit karenge dfs call lga kar jisme curr node change karke v kar denge
     void dfs(int u, int vis[], vector<int> &ans, vector<int> adj[]){
              
            ans.push_back(u);
            vis[u] = 1;
            for(auto it: adj[u]){
                if(!vis[it]){
                    dfs(it, vis, ans, adj);
                }
                
            }
            
        }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
      vector<int> ans;
        int vis[V] ={0};
       
       dfs(0, vis, ans, adj);
        return ans;
    }


