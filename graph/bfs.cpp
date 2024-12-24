// Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
// Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.


// Example 1:

// Input:
// V = 5, E = 4
// adj = {{1,2,3},{},{4},{},{}}
// Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        //we are given adjacency list of vertices
        //and bfs traveral start from 0 so we will push 0 in Q first
        queue<int> q;
        q.push(0);
        vector<bool> vis(V, false);//to keep track whether a vertex is visited or not, initially all are unvisited so false
        //koi bhi vertex q m ek hi baar ayegi to q m push karte hi , vis ko true ko mark kaardena
        //BFS m queue k andar front elem ki nearest unvisited neighbour push hote hai
        vis[0] = true;
        vector<int> bfs;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            bfs.push_back(u);
            for(auto it : adj[u]){
                //traversing all the neighours of u
                //push the unvisited once in q and then mark them as visited
                if(!vis[it]){
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
        return bfs;
        
    }
    //Total degree of graph is 2E , as every node is associated with 2 edges
    // time complexity
    //a node goes once into the bfs it runs for all its neighbours the inner for loop runs for all its degrees an total degrees in graph is 2E 
    //so outer loop runs for O(V) and inner loop runs for O(2E)
    //so total time complexity for BFS of graph is O(V+E)

    //space complexity - queue, vis, ans
    //O(3n)