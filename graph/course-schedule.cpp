// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.


//we need to find if topological sort order will exist for the given graph or not since we new requirement for topological sort is directed acyclic graph since there is dependency our graph will be directed so we need to only check that graph is cyclic or not
    bool iscycle(int src, vector<int> adj[], vector<bool> &vis,vector<bool> &recpath){
        vis[src] = true;
        recpath[src] = true;
        for(auto it: adj[src]){
            if(!vis[it]){
                
                if(iscycle(it, adj, vis, recpath)){
                    return true;
                }
            }else{
                if(recpath[it]){
                    return true;
                }
            }
        }
        recpath[src] =false;//jis src node ka directed graph m koi neigh exist nhi karta usko rec path se hatake usse backtrack karna hoga
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i = 0; i<prerequisites.size(); i++){
            int u = prerequisites[i][1];//kyuki is question m [a,b] given hai or course a se phle b lena jaruri hai it means a is dep on b edge aisi bnegi b->a == u->v , that's why u hmare vector k 1 index p h and v hmare vector k 0th index p 
            int v = prerequisites[i][0];
            adj[u].push_back(v);
            //   adj[v].push_back(u);

        }
        vector<bool> vis(numCourses, false);
        vector<bool> recpath(numCourses, false);
        for(int i = 0; i<numCourses; i++){
            if(!vis[i]){
            if(iscycle(i,adj,vis, recpath)){
            return false;//cycle exist so return false
        }
            }
        }
        return true;//otherwise return true
        

    }