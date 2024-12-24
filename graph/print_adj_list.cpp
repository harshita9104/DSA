 // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>> adj(V);//V is the total num of vertex 
        //and this 2d vector will store the list of neighbours of each vertex
        //we are given a vector edges, which contains pair of vertices for each edge
        for(int i = 0; i<edges.size(); i++){
            //acess the vertices of each edge
            int u = edges[i].first;
            int v = edges[i].second;
            //u or v edge se connected hai to vector adj k uth index p v ko push kardo and vice versa
            adj[u].push_back(v);
            adj[v].push_back(u);


        }
        return adj;
        
    }
//     Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 0-based indexing is followed everywhere.

// Example 1:

// Input:
// V = 5, E = 7
// edges = {(0,1),(0,4),(4,1),(4,3),(1,3),(1,2),(3,2)}
