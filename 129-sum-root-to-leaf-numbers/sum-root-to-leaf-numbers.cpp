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
//string denotes one path fro root to leaf and each rec call will have diff path so each call shd have its own copy o path so pass by val
   
    void solve(TreeNode* root, string s, int &ans){
        if(root == NULL) return; // just return if node is null

        s += to_string(root->val); // add current digit to path

        // If it's a leaf node, convert path to int and add to ans
        if(root->left == NULL && root->right == NULL){
            ans += stoi(s);
            return;
        }

        // otherwise, keep going down the tree
        solve(root->left, s, ans);
        solve(root->right, s, ans);
    }
    int sumNumbers(TreeNode* root) {
        string s = "";
        int ans = 0;
        solve(root, s, ans);
        return ans;
    }
};