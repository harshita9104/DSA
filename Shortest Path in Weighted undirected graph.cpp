// You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest weight path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.

// The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.

class Solution {
  public:
  typedef pair<int,int> p;
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        unordered_map<int, vector<p>> adj;//this adj list will store ek node k neigh or or edge cost k pairs
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> shortest(n+1, INT_MAX);
        vector<int> parent(n+1);
        for(int i = 1; i<=n; i++){
            parent[i] =i;
        }
        vector<int> vis(n+1, 0);
        shortest[1] = 0;//kyuki 1 se 1 par jaane m 0 dist h isko hi pq m push krdo
        pq.push({0,1});//pq m cost from src to node, node aayega
        while(!pq.empty()){
            int costtonode = pq.top().first;
            int node = pq.top().second;
            
            // ans += costtonode;
            pq.pop();
            if(vis[node])continue;
            vis[node] = 1;
            //ab is node k neigh par jaao adj list k thr or src se neigh tk ka shortest path find kro
            for(auto &neigh : adj[node]){
                int adjnode = neigh.first;
                int edgecost = neigh.second;
                if(costtonode + edgecost < shortest[adjnode]){
                    shortest[adjnode] = costtonode+ edgecost;
                    pq.push({costtonode+ edgecost, adjnode});
                    parent[adjnode] = node;//is tarah se adjnode ki shortest dist from src to adjnode bhi pq m chli gyi 
                    //or parent bhi parent vector m note ho gya
                    //ab agar baad m is adjnode ka koi or shorter dist milta h src se to vo bhi consider ho jaega or uska naya par bhi update ho jaega
                    
                }
            }
            
        }
        //agar shortest[n] abhi bhi INT_MAX h yani us tk pahuchne ka koi path nhi return -1
        if(shortest[n] == INT_MAX)return {-1};
        // ab we have par vector jisse path trace krna h par vector m index node ko represent kr rha
        //or uske corresponding val uske par ko
        //hmme shuru vha se krna h jis node ka par vo khud ho yani src node//
        //but traverse last se krte h
        vector<int> path;
        int node = n;
        //piche se traverse kr rhe shuru m to n aayega path m 
        //or last m src node to while loop tab rukega jis node ka par vo khud ho
        while(parent[node] != node){
            path.push_back(node);
            //ab iske baad curr node ka jo par h vo aayega 
            //or while loop m hm har baar node ko push kar rhe to node ko update krdo or par k val dedo
            node = parent[node];//taki next push path m curr node k par node ka ho
        }
        //jab src node aaya to while loop khtm hua kyuki vo khud hi khud ka par tha to usko bhi push krdok
        path.push_back(1);
         path.push_back(shortest[n]);
        //ab is path ko reverse krdo
        reverse(path.begin(), path.end());
        return path;
        
        
        
    }
};
