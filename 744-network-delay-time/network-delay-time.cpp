class Solution {
public:
    typedef pair<int, int> p;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for(vector<int> &edge : times){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            mp[u].push_back({v,w});
        }
        vector<int> shortest(n+1, INT_MAX);//initially har node par pahuchne k liye int max lag rha
        shortest[k] = 0;//src node khud hi p pahuchne k liye 0 time lgega
        //pq lo usme {src to node ka dist , src} daaldo
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            //abhi pq k top par src khud h baad m src ka koi neigh hoga tab cost m src to neigh ka time hoga, or jab ye curr node on top of pq apne neigh tk ka dist dekhega to hm edge relaxation krenge ki abhi tk jo shortest dist nikala vo small h ya aise traverse karke edge wt add kiya vo
            int cost = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for(auto &neigh : mp[u]){
                //ab is node k sare neighbors tk ka dist dekho 
                int node = neigh.first;
                int wt = neigh.second;
                //do edge relaxation now cost is time from src node to curr node usme wt add kro
                if(wt + cost < shortest[node]){
                    shortest[node] = wt +cost;
                    //ab kyuki src to node tk ka shortest time nikal gya h isko pq m daldo taki isnode k neigh ka edge relaxation hoke unka bhi shortest time nikale
                    pq.push({shortest[node], node});
                }

            }
        }
        int ans = INT_MIN;
        for(int i = 1; i<=n; i++){
            ans = max(ans, shortest[i]);
        }
        if(ans != INT_MAX)return ans;
        return -1;
    }
};