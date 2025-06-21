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
// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    // Helper function to perform DFS and find all root-to-leaf paths with the given sum
    void solve(TreeNode* root, int pathsum, vector<int>& path, vector<vector<int>>& result, int targetSum) {
        if (root == NULL) return; // Base case: If node is null, just return

        // Add current node's value to pathsum and path
        pathsum += root->val;
        path.push_back(root->val);

        // If the current node is a leaf node (no left and right children)
        // and the pathsum equals the targetSum, add the path to result
        if (root->left == NULL && root->right == NULL && pathsum == targetSum) {
            result.push_back(path);
        } else {
            // Continue DFS on left and right children
            solve(root->left, pathsum, path, result, targetSum);
            solve(root->right, pathsum, path, result, targetSum);
        }

        // Backtrack: remove the current node from path before returning
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result; // Stores all valid paths
        vector<int> path;           // Current path being explored

        // Start DFS only if the tree is not empty
        // Mistake correction: Do not access root->val if root is NULL
        solve(root, 0, path, result, targetSum);

        return result;
    }
};