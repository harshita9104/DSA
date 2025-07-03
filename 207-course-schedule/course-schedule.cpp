class Solution {
public:
   
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;//create adj list from given 2d vector
        vector<int> indegree(numCourses, 0);
        for(vector<int> &edge: prerequisites){
            int u = edge[1];
            int v = edge[0];
            //it is given in q that in [a,b] a is dependent on b 
            //so there is edge from b to a
            //so u is b, and v is a in prerequisites[i]
            adj[u].push_back(v);
            indegree[v]++;
            // adj[v].push_back(u);
        }
        vector<bool> visited(numCourses, false);
     

        // the question is all about is a topo sort possible for this graph
        //so we just need to check if the graph is acyclic or not
        //using bfs 1st we need to find indegree of all nodes then push the indegree 0 nodes in q first
        //then as u pop a node from q for all its neighbors do indegree--, and only push a node inside q when indegree of a node becomes 0
        int count=0;
       queue<int> q;
       for(int i =0; i<numCourses; i++){
        if(indegree[i] == 0){
            q.push(i);
            count++;
            visited[i] = true;
        }
       }
       while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int &v : adj[curr]){
            if(!visited[v]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                    count++;
                }
            }
        }
       }
    return count == numCourses;
    }
};