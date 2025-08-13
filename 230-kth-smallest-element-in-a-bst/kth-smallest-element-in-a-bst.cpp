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
vector<int> values;
void solve(TreeNode* root , int k){
    if(root == NULL)return;
    values.push_back(root->val);
    solve(root->left, k);
    solve(root->right, k);
}
    int kthSmallest(TreeNode* root, int k) {
        solve(root, k);
        sort(values.begin(), values.end());
        return values[k-1];
    }
};