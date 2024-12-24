// There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

// You want to determine if there is a valid path that exists from vertex source to vertex destination.

// Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.


bool helper(int n, vector<int> adj[], int source, int destination, vector<bool> &vis){
        if(source == destination){
            return true;//it means a path exist from src to dest
        }
        //now we will traverse thr the graph thr dfs and if a path exist then we will return true otherwise false
        int u = source;
        vis[u] = true;
        for(auto it : adj[u]){
            if(!vis[it]){
                //in every recursive call we are changing the source so every time the for loop will run for a new value and this way it will try to reach dest by exploring the neighbours of each vertex every time a recursive call is made
               if( helper(n, adj, it, destination, vis)){
                return true;//
               }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination ) {
        vector<int> adj[n];
        //since it is undirected graph, and we aare given each edge 
        //so we will traverse thr each edge and us edge k dono vertices k neighbours m yani unke corresponding adj list m ek dusre ko push krdo
        for(int i = 0; i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        return helper(n,adj, source,destination, vis);
    }