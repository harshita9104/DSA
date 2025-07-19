class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 0|| m == 0|| grid[0][0] != 0)return -1;
        queue<pair<int, int>> q;
        q.push({0,0});
        grid[0][0] =1;
        int level = 0;
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1}, {-1, 1}, {1, -1}};
        while(!q.empty()){
            int levelsize = q.size();
            while(levelsize--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
             if(x == m-1 && y == n-1)return level +1;
            for(auto &it: dir){
                int x_ = x + it[0];
                int y_ = y+ it[1];
               
                if(x_ >= 0 && x_<n && y_ >= 0 && y_ < m && grid[x_][y_] == 0){
                    q.push({x_, y_});
                    grid[x_][y_] = 1;
                    
                }
            }
            }
            //curr node k same level k sare neigh q m chle gye ab next level or jaao
            level++;
//hm sirf bfs m level count kr rhe level +1 is our ans in end 
        }
        return -1;//if i am not able to reach end corner
    }
};