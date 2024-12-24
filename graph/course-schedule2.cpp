// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

//first check that graph is cyclic or not if u got cyclic return empty arr
//if after whole graph traversed and no cycle detected then do topological sort and return the order as i stack
void helper(int src, vector<int> adj[], vector<bool> &v, stack<int> &s){
    v[src] = true;
    for(auto it: adj[src]){
        if(!v[it]){
            helper(it,adj,v,s);
        }
    }
    s.push(src);
}

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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i = 0; i<prerequisites.size(); i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
            //   adj[v].push_back(u);

        }
        vector<int> result;
        stack<int> s;
        vector<bool> vis(numCourses, false);
        vector<bool> recpath(numCourses, false);
        for(int i = 0; i<numCourses; i++){
            if(!vis[i]){
            if(iscycle(i,adj,vis, recpath)){
            return {};//cycle exist so return false
        }
            }
        }
         //cycle dont exist 
         //use a diff boolean vector to track visited node
         vector<bool> v(numCourses, false);
        for(int i = 0; i<numCourses; i++){
            if(!v[i]){
                helper(i,adj, v,s);
            }
        }
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        return result;//otherwise return true
        

    }