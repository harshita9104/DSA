/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    // void solve(TreeNode* root,vector<int> path, int &ans){
    //     if(root == NULL)return;
    //     path.push_back(root->val);
    //     if(root->left == NULL && root->right == NULL){
    //         // for(int a= 0; a< path.size()-1; a++){//a pointer will be always behind b so a ko 2nd last elem tk leke jao b ko last tk
    //         //     for(int b = a; b< path.size(); b++){
    //         //         ans = max(abs(path[a] - path[b]), ans);
    //         //     }
    //         // }
    //         int a = INT_MIN;
    //         int b = INT_MAX;
    //         for(int i= 0; i< path.size(); i++){
    //             a= max(a, path[i]);
    //             b = min(b, path[i]);
    //         }
    //         ans = max(abs(a - b), ans);
    //     }
    // //agar leaf node nhi h to aage traverse karo tree m by making rec call 
    // //func void hai isliye root->left ko assign nhi kiya    
    //      solve(root->left, path, ans);
    //     solve(root->right, path, ans);

    // }
    // int maxAncestorDiff(TreeNode* root) {
    //     //i will evaluate all the paths from root to leaf as this path will be in the order from ancestor to desc and then iterate over path and find max diff bw a and b where a occurs before b in path
    //     vector<int> path;
    //     int ans = INT_MIN;
    //     solve(root, path, ans);
    //     return ans;


    //above soln ko optimise krne k liye ,
    // jab hm trverse kr rhe ek particular path m tab us path ka max or min val nikalte jaao or aisa func banao jo root or maxv , minv dono leke har call m maxv, minv, calc karle
//maxv or minv ko by value pass kiya taaki har func call apni alg copy bnaye , kyuki har path k liye ye values alg hogi
    int solve(TreeNode* root, int maxv, int minv){
        
        if(root == NULL){
            return abs(maxv - minv);
            
        }
        //current root ko maxv , minv nikalne k liye evaluate kro
        maxv  = max(maxv, root->val);
        minv = min(minv, root->val);
        int leftpath = solve(root->left, maxv, minv);//root k left child wale path ka abs a-b return kar rha h
        int rightpath = solve(root->right, maxv, minv);//root k right child wale path ka abs a-b return kar rha hai 
        return max(leftpath, rightpath);//dono path m se jo bhi max diff h vo return kro//ye last wali line har baar execute hogi kyuki root ki left subtree ki bhi left or right subtree hai or har subtree k liye leftpath or rightpath cal hoga or usme se max return hoga current subtree kisi root ki left ya right subtree hogi to us root k liye ye wale jaake store ho jaegi phir is current root ki max val uske upar wale node ko return hogi

    }
    int maxAncestorDiff(TreeNode* root) {
        int maxv = INT_MIN;
        int minv = INT_MAX;
        return solve(root, maxv, minv);      

    }
};