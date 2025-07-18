class Solution {
public:
    typedef pair<int, int> p;
    int minCostConnectPoints(vector<vector<int>>& points) {
        //consider representing each point with its index number connection bw two points will be edge bw those two nodes
        // i will create a adj list which will store a list of pairs ki ek node baaki sare nodes se connected hai or corresponding edges ka weight
        unordered_map<int, vector<pair<int, int>>> adj;
        for(int i =0; i< points.size()-1; i++){
            for(int j = i +1; j <points.size(); j++){
                int xi = points[i][0];
                int xj = points[j][0];
                int yi = points[i][1];
                int yj = points[j][1];
                int wt = abs(xi-xj) + abs(yi-yj);
                adj[i].push_back({j, wt});
                //undirected graph hai to vice versa neigh bhi daldo
                adj[j].push_back({i, wt});
            }
        }

        int cost = 0;
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<bool> mstset(points.size(), false);//initially nobody in pq
        //pq m node ki edge ka wt or node daalo,  
        //ab uske sare neigh ki edges ko bhi pq m daaldo //
        //or jo top par h vahi cost m consider hoga kyuki vahi edge min h uske baad usko mstset m daaldo
        //agar koi pq k top par node h vo already mst set m present h to kuch mt kro
        pq.push({0, 0});
        while(!pq.empty()){
            int currcost = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(mstset[u] == true)continue;
            //nhi h to isko mstset m daalkar cost m include krlo
            mstset[u] = true;
            cost += currcost;
            for(auto &neigh : adj[u]){
                int v = neigh.first;
                int edgecost = neigh.second;
                if(mstset[v] == false){
                    //mst set m nhi h ye neigh node to isko pq m daldo
                    pq.push({edgecost, v});
                }
            }
        }
        return cost;
    }
};