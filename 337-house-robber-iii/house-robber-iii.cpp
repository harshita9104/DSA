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
    pair<int, int> solve(TreeNode* root){
        if(!root) return {0,0};
        //For each node, calculate two values:
// r: Maximum sum when robbing the current node (i.e., sum of the current node's value plus the sums of its grandchildren).
// nr: Maximum sum when not robbing the current node (i.e., sum of the maximum values from both children).
// Use a helper function solve(root) that returns a {r, nr} pair.
// Compute the final answer by taking max(result.first, result.second).
// Base Case:

// If root == nullptr, return {0,0} because an empty tree contributes nothing.
// Recursive Calculation:

// Recursively compute {r, nr} for left and right children.
// Compute:
// r = root->val + left.nr + right.nr
// nr = max(left.r, left.nr) + max(right.r, right.nr)
// Final Computation:

// Return max(result.first, result.second) to ensure we get the maximum sum without violating the constraints.


        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        int r = root->val + left.second + right.second;
        int nr = max(left.first, left.second) + max(right.first, right.second);
        return {r, nr};
    }
    int rob(TreeNode* root) {
        pair<int, int> result = solve(root);
        return max(result.first, result.second);
    }
};