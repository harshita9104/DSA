bool check(int start,int V,vector<vector<int>>& graph,vector<int> &color)
    {
     queue<int> q;
	    q.push(start);
	    
	   // int color[V] = {-1};//initially all the node are not colored
	    color[start] = 0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        for(auto it : graph[node]){
	            //traverse thr the neigh of node and if they are not colored then color them with opp colr and push them in q
	            if(color[it] == -1){
	                color[it] = !color[node];
	                q.push(it);
	            }else if(color[it] == color[node]){
	               // if the neigh are colored already then check if their color is same as parent node if so then return false
	              
	                   return false;
	               }
	            }
	        }
	    
	    //if no false is return then it is bipartite
	    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int V= graph.size();

        vector<int> color(V,-1);
	    for(int i=0;i<V;i++)
	    {//check for each component in graph 
	        if(color[i]==-1)
	        {
	            if(check(i,V,graph,color)==false)
	            {
	                return false;
	            }
	            
	        }
	        
	    }
	    return true;

    }