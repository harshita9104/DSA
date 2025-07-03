class Solution {
public:
   bool iscyclic(int u,unordered_map<int, vector<int>> &adj, vector<bool> &visited, vector<bool> &recpath){
    visited[u] = true;
    recpath[u] = true;
    for(int &v : adj[u]){
        if(!visited[v]){
            if(iscyclic(v,adj, visited, recpath))return true;//agar aage k call m kahi cycle mili or true return hoke aa rhi hogi to hm return kr dengge
        }else{
            //neigbor visited h to check kro recpath m kya
            if(recpath[v] == true)return true;
        }
    }
    //if we have reached a node which doesnt have neigh then backtrack and remove it from recpath
    //and this is end of curr rec path so return false that no cycle found on this path
    recpath[u] = false;
    return false;
   }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;//create adj list from given 2d vector
        for(vector<int> &edge: prerequisites){
            int u = edge[1];
            int v = edge[0];
            //it is given in q that in [a,b] a is dependent on b 
            //so there is edge from b to a
            //so u is b, and v is a in prerequisites[i]
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> recpath(numCourses, false);

        // the question is all about is a topo sort possible for this graph
        //so we just need to check if the graph is acyclic or not
        //in directed we check cyclic using recpath , if we encounter a neighbor
        //which part of same recapth then cycle exist
        for(int i =0; i<numCourses; i++){
            if(!visited[i] && (iscyclic(i, adj, visited, recpath)))return false;
        }
        return true;
    }
};