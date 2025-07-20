class Solution {
public:
typedef pair<int, pair<int, int>> p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> result(n, vector<int>(m , INT_MAX));
        vector<vector<int>> dir = {{1,0}, {0,1},{-1,0},{0,-1}};
       priority_queue<p, vector<p>, greater<p>> pq;
       result[0][0] = 0;//path m sirf yhi coord hai to abhi abs diff =0
       pq.push({0,{0,0}});//pq will store diff , pair of coord
       while(!pq.empty()){
        auto curr = pq.top().second;
        int diff = pq.top().first;
        int x = curr.first;
        int y = curr.second;
        pq.pop();
        for(auto &neigh: dir){
            int x_ = x + neigh[0];
            int y_ =y + neigh[1];
            if(x_ >= 0 && x_ < n && y_>= 0 && y_ <m ){
                int adjdiff = max(abs(heights[x_][y_] - heights[x][y]), diff);
                
                if(adjdiff < result[x_][y_]){
                    result[x_][y_] = adjdiff;
                    pq.push({adjdiff, {x_, y_}});
                }

            }
        }
       }
       return result[n-1][m-1];
    }
};