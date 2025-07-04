class Solution {
public:
int m;
int n;
int peri ;
void dfs(vector<vector<int>>& grid, int i, int j){
    //mujhe perimeter tab inc karna hai jab mai ek island par khadi hu or uske neigh m ya to mujhe water mile ya out of bound ja rha ho , in sari condn m aage nhi ja skte to return kar jaana h taaki dusra side ka neigh island explore kr paye
    if(i<0 || i>= m || j<0|| j>=n || grid[i][j] == 0){
        peri++;
        return;
    }
    //agar koi island phle se visit kar lia hai to usse -1 kardenge or uspe aagye to vha se return kr jaenge
    if(grid[i][j] == -1)return;//visited island h already
    //or else hm ek new island par khade h to neigh call krne se phle usko visited mark krdo
    grid[i][j] = -1;
    //har island k 4 neigh hai to charo par dfs call maro 
    dfs(grid, i+1,j);
    dfs(grid, i, j+1);
    dfs(grid, i-1, j);
    dfs(grid, i, j-1);
    
    
}
    int islandPerimeter(vector<vector<int>>& grid) {
     m = grid.size();
        n = grid[0].size();
        peri =0;
        for(int i =0; i< m; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j] == 1){
                    //ek island mila to usko pakad k dfs call krdo poora island apne aap traverse ho jaega
                    dfs(grid, i, j);
                    return peri;
                }
            }
        }
        return -1;
    }
};