	//Function to return list containing vertices in Topological order.
	//kyuki topological sort order m sabse phle vo node aate hai jo kisipe depend nhi hai...jinki indegree=0 hai ...yani unki taraf koi edge nhi aati hai
	//to hm 
vector<int>	bfs(vector<int> adj[], vector<int> &indeg, vector<int> &result){
	    queue<int> q;
	    for(int i = 0; i < indeg.size(); i++) {
				//topological order milne k liye graph ka DAG hona jaruri hai or DAG m atleast ek node aisa hota hai hai jiski indeg=0 ho, tabhi to graph acyclic bnega to q m atleast ek elem initially to push hoga hi
        if(indeg[i] == 0) {//initially topo sort order m vo elem hote hai jinki indeg=0 ho, to jinki indeg =0 hai unko q m push kardo q is FIFO , to jisko phle push karoge vo front p aayega
            q.push(i);
        }

	    }
	    while(!q.empty()){
	        int curr = q.front();
	        q.pop();
	        result.push_back(curr);
					//kyuki hmne curr ko pop kar dia ahi q se to uski sari dependencies htani hogi
	        for(auto v: adj[curr]){
	            indeg[v]--;//isiliye uske sare neighbors ki ideg-- kardo
	            if(indeg[v] == 0){//agar kisi neigh ki indeg 0 ho jae to usse q m push krdo
	                q.push(v);
	            }
	        }
	        
	    }
	    return result;
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> result;
	    vector<int> indeg(V);
	    for(int i = 0; i<V; i++){
				//u->v, v is neigh of u, v ki indegree =1, to har ek node k liye iterate kar rhe or unke neighbors ki indegree ko ++ kardenge
	        for(auto it: adj[i]){
	            indeg[it]++;
	        }
	    }
	    return bfs(adj,indeg, result);
	    
	    
	}
	//note-
	// if after processing all nodes some nodes still have non zero indegree it indicates presence of cycle
	//to detect cycle using bfs we use kahn only
	//also since DAG has condition that atleast on enode shd have indeg=0 && at least one node shd have outdeg =0 u can check that condition for cycle detection as well