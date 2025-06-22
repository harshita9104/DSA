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
    int maxsum = INT_MIN; // Tracks the maximum path sum found so far

    // Helper function to compute the maximum path sum and update maxsum
    int solve(TreeNode* root) {
        if (root == NULL) return 0; // Base case: null node contributes 0

        // Recursively compute the max path sum from left and right subtrees
        int l = solve(root->left);
        int r = solve(root->right);

        // Possible path sums at this node:
        // 1. Path goes through left child, current node, and right child (could be the answer)
        int complete = l + r + root->val;
        // 2. Path goes through current node and only one child (left or right)
        int oneside = max(l, r) + root->val;
        // 3. Path only includes the current node (might be optimal if children are negative)
        int onlyroot = root->val;

        // The maximum path sum at this node could be any of the three cases above
        maxsum = max({maxsum, complete, oneside, onlyroot});

        // When returning to the parent, you can only choose one direction (left or right)
        // or just the root (because you can't use both sides in parent paths)
        return max(oneside, onlyroot);
    }

    int maxPathSum(TreeNode* root) {
        solve(root); // Start postorder traversal from root
        return maxsum; // Return the maximum path sum found
    }
};