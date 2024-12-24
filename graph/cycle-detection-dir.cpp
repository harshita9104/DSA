// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

// Function to detect cycle in a directed graph.
    bool helper(int src, vector<int> adj[], vector<bool> &vis,  vector<bool> &recpath){
        vis[src] = true;//jis curr src node k liye rec call hui usse visit karlo
        recpath[src] = true;//or usse recpath m add karlo
        //fir uske neighbors p traverse karo or unvisited ko visit karo 
        //or directed graph m cyclic condition hoti hai  ki
        //agr curr src node ka neighbour , recpath m exist karta hai iska mtlb ham ghum k vahi aa gye h jha phle bhi aa chuke hai to cycle exist karti hai
        for(auto it: adj[src]){
            if(!vis[it]){
                //unvisited hai to rec call kardo taaki visit ho jae
                //agar is rec call m further kahi p hme cycle milti hai to helper fun true return hoke aa rha hoga to hm bhi true return kr denge
                //is rec call m src node it hogi , hm rec call usko visit karne k liye kar rhe hai
                if(helper(it, adj, vis, recpath)){
                    return true;
                }
            }else{
                //visited, 
                //agar curr src node ka koi neighbor jo ki visited hai vo rec path m exist karta hai to cycle exist krti hai
                if(recpath[it]){
                    return true;
                }
            }
        }
        //directed graph m parent node neighbour nhi hota to agr hm kisi aise node p pahuch gye hai 
        //jiska koi neigh exist nhi karta to hme backtrack karna hoga uss curr src node ko recpath se hta do 
        recpath[src] = false;
        //or kyuki is rec path m cycle exist nhi karti false return kardo
        return false;
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V, false);
        vector<bool> recpath(V, false);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(helper(i,adj,vis,recpath)){
                    return true;
                }
            }
        }
        return false;
    }