  // Function to detect cycle in an undirected graph.
  //using BFS
    bool helper(int start, vector<int> adj[], int vis[] ){
         vis[start] = 1;
        queue<pair<int, int>> q;//node , parent node
        q.push({start,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parentnode = q.front().second;
            q.pop();
            for(auto adjacentnode : adj[node]){
                //push only those neighbours in queue which are unvis
                if(!vis[adjacentnode]){
                    q.push({adjacentnode, node});
                    vis[adjacentnode] = 1;
                }else if(adjacentnode != parentnode){
                    //if it is visited neigh of node and it is not parent node it means this neigh of node was visited from the other direction it means a cycle exist
                    return true;
                }
            }
        }
        return false;
    }
     //using DFS
     bool dfs(int node, int parentnode, vector<int> adj[], int vis[]){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it,node,adj,vis) == true){
                    return true;
                }
            }else{
                //if it visited but its not a parent it means a cycle exist
                if(it != parentnode){
                    return true;
                }
            }
            
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
      //to ensure all components are checked for cycle
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(helper(i,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }

   
