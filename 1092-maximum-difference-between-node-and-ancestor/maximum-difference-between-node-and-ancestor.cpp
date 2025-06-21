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
    
            void solve(TreeNode* root,vector<int> path, int &ans){
        if(root == NULL)return;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            for(int a= 0; a< path.size()-1; a++){//a pointer will be always behind b so a ko 2nd last elem tk leke jao b ko last tk
                for(int b = a; b< path.size(); b++){
                    ans = max(abs(path[a] - path[b]), ans);
                }
            }
        }
    //agar leaf node nhi h to aage traverse karo tree m by making rec call 
    //func void hai isliye root->left ko assign nhi kiya    
         solve(root->left, path, ans);
        solve(root->right, path, ans);

    }
    int maxAncestorDiff(TreeNode* root) {
        //i will evaluate all the paths from root to leaf as this path will be in the order from ancestor to desc and then iterate over path and find max diff bw a and b where a occurs before b in path
        vector<int> path;
        int ans = INT_MIN;
        solve(root, path, ans);
        return ans;

    }
};