	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    // Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dis(V, INT_MAX);//initialise dist of all the nodes from source as infinity
        dis[S] = 0;//dist of src from src is 0
        // since we want the shortest path always so we will use priority queue to store pair of dist and node/vertex
        priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(make_pair(0,S));//dist,node
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(auto it: adj[u]){//iterating thr the vectors which contain info abt the edges
            //it points to a vector whose 0th index contain neigh of u and 1st index contain weight of tht edge connecting u and v
            int v = it[0];
            int wt = it[1];
            //edge relaxation for neigh
            if(dis[u] + wt < dis[v]){
                dis[v] = dis[u] +wt;//replace with the shortest dist and push the node in pq
                pq.push({dis[v], v});
            }
                
            }
            
        }
        return dis;
    }