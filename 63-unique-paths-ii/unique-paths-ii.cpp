class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int>prev(n,0);
        vector<int>curr(n,0);

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(obstacleGrid[row][col]){
                    curr[col]=0;
                    continue;
                }
                if(row==0 && col==0){
                    curr[col]=1;
                    continue;
                }

                int up=0;
                if(row>0)up+=prev[col];
                int left=0;
                if(col>0)left+=curr[col-1];
                curr[col]=up+left;
            }
            prev=curr;
        }

        return prev[n-1];
    }
};