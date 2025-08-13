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
int count  =0;
void solve(TreeNode* root, int maxpath){
    if(root == NULL)return;
    if(root->val >= maxpath){
        count++;
        maxpath = root->val;

    }
    solve(root->left,maxpath);
    solve(root->right, maxpath);
}
    int goodNodes(TreeNode* root) {
        int maxpath = root->val;
        solve(root, maxpath);
        return count;
    }
};