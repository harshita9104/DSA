class Solution {
public:
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();//no of rows
        int n = mat[0].size();//no of col
         unordered_map<int, vector<int>> mp;
      //(i-j, family of elem along this diagonal)
        //map bnalo i-j constant hai matrix k diagonally aligned elem k liye , key value of map will be i-j
        for(int i = 0;i<m; i++){
            for(int j = 0; j<n; j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }
        //sort karo map m key value k corresponding vector m jo diagonally aligned elem store kiye h unko
        for(auto &it: mp){
            sort(it.second.begin(), it.second.end());
        
        }
        //ab in sorted vector ko hme matrix m arrange karna hai since it is easier to pop_back elem from back of vector(koi elem ko shift nhi krna pdega) hm matrix ko reverse traverse karenge or vector ka last elm matrix m daal k pop kardo 
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                mat[i][j]= mp[i-j].back();
                mp[i-j].pop_back();

            }
        }
    return mat;
    }
};