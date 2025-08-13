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
vector<string> result;
void solve(TreeNode* root, string path){
    //each rec call will have its own copy of path so pass by val
    if(root == NULL)return;
    if(root->left == NULL && root->right == NULL){
        path+= to_string(root->val);
    result.push_back(path);
        return;
    }
    path += to_string(root->val);
    path += "->";
    solve(root->left, path);
    solve(root->right, path);
    path.pop_back();
    

}
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        solve(root, path);
        return result;
    }
};