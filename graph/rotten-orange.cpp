//since all the rotten oranges at level 0 are rotting all the fresh oranges at level 1 which are at a dist of 1 from rotten oranges simaltaneously at the same time we are traversing level wise so it can be solved using bfs
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //2d visited matrix to keep track of visited oranges in bfs
        int vis[n][m];
        int countFreshOrange = 0;
        queue<pair<pair<int, int>, int>> q;//we will psuh the oranges in queue as we visit them, it will store pair of {{row no. , col no.}, time }
        //push the rotten oranges present in the grid intially in the queue at time 0 and mark them visited  by traversing the grid using nested for loop 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ; j++){
                //push only rotten oranges that is the oranges whose grid val is 2
                if(grid[i][j] == 2){
                    //q will store pair of coordinates of rotten orange in matrix & t
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }else{
                    vis[i][j] = 0;//mark the other oranges as unvisited
                }
                if (grid[i][j] == 1) {
                    countFreshOrange++;
                }
            }
        }
        //q.empty() means there is no rotten orange in the grid and countFreshOrange = 0 means we will rotten the freshoranges in 0 mins
       
        int tm = 0;
//to get the value of updated row and col as we trverse up, down, right, left
int drow[] = {+1, -1, 0, 0};
int dcol[] =   {0, 0, +1, -1};
        while(!q.empty()){
          int r = q.front().first.first;
          int c = q.front().first.second;
          int t = q.front().second;
          tm = max(tm , t);
          q.pop();
          for(int i = 0; i<4; i++){
            int nrow = r+drow[i];
            int ncol = c+dcol[i];//update the row and col 
            //check the updated row and col is valid or not 
            //since we will push only fresh and unvisited oranges in queue by visiting them at time t+1
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                q.push({{nrow, ncol}, t+1});
                vis[nrow][ncol] = 2;
                countFreshOrange--;
            }
          }
        }
        //after the q becomes empty
        //check that were all the fresh oranges converted to rotten or not, if no then retirn -1 other wise return tm
        //this will throw tle
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m ; j++){
    //         if(grid[i][j] ==1 && vis[i][j] != 2 ){
    //             return -1;
    //         }
    //     }
    // }
   if (countFreshOrange == 0)
            return tm;
        return -1;
    }