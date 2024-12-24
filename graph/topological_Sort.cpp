// Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid topological sorting of the graph.

//   problem at hand is to perform a topological sort of a Directed Acyclic Graph (DAG). Topological sorting of a graph is a linear ordering of its vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.

// Why Use a Stack?
// In Depth-First Search (DFS) for topological sorting, we want to ensure that once we finish processing a node and its descendants, this node should be added to the result. By using a stack, we can store nodes such that when we pop from the stack, we get the nodes in the correct topological order. Nodes that finish last should appear last in the result, and since stacks follow Last In First Out (LIFO) order, it naturally fits this requirement.

// Approach
// Visited Array: To keep track of visited nodes and ensure we don't process the same node more than once.
// DFS Traversal: For each node, if it hasn't been visited, perform a DFS. During DFS, we visit all the unvisited neighbors of the current node.

// In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.

	//Function to return list containing vertices in Topological order. 
	void helper(int src,vector<bool> &vis, vector<int> adj[], stack<int> &s ){
	    vis[src] = true;
	    for(auto it: adj[src]){
	        if(!vis[it]){
	            helper(it,vis,adj,s);
	        }
	    }
	    s.push(src);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> s;
	    vector<bool> vis(V, false);
	    for(int i = 0; i<V; i++){
	        if(!vis[i]){
	            helper(i, vis,adj,s);
	        }
	    }
	   vector<int> result;
	   while(!s.empty()){
	       result.push_back(s.top());
	       s.pop();
	   }
	   return result;
	}