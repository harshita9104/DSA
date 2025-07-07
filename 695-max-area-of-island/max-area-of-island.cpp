class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int& area) {
        int m = grid.size();
        int n = grid[0].size();

        // Boundary or already visited or water
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1) return;

        grid[i][j] = 2; // Mark as visited
        area++;

        // Explore all 4 directions
        dfs(i - 1, j, grid, area); // up
        dfs(i + 1, j, grid, area); // down
        dfs(i, j - 1, grid, area); // left
        dfs(i, j + 1, grid, area); // right
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxarea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs(i, j, grid, area);
                    maxarea = max(maxarea, area);
                }
            }
        }
        return maxarea;
    }
};
