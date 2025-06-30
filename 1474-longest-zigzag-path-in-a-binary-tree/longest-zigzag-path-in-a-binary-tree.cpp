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
int longest =0;
void solve(TreeNode* root, int path, bool goleft){
    if(root == NULL)return;
    longest = max(longest, path);
    if(goleft == true){
        solve(root->left, path +1,false );//left m jaana tha or left m gye to path++ or ab next call m right m jana hoga isliye goleft = false
        solve(root->right, 1, true);//left m jana tha par right m chle gye to zig zag pattern break ho gy path 1 se start hoga 
    }else{
        solve(root->left, 1, false);
        solve(root->right, path+1, true);
    }
}
   int longestZigZag(TreeNode* root) {
        bool goleft = true;
        int path =0;
        solve(root, 0, true);
        return longest;
    }
};