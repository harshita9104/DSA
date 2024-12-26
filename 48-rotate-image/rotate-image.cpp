class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // matrix ka transpose nikalo or phir usse reverse krdo
        int m = matrix.size();//no of row
        int n = m;//given
        for(int i = 0; i<m; i++){
            for(int j = i; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reverse karo rows ko
        for(int i = 0;i<m;i++ ){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};